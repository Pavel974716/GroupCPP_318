#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <atomic>
#include <mutex>
#include <new>

// ����楢�� ����
class RingBuffer {
public:

    // explicit - ����頥� ���� �८�ࠧ������ ⨯�� �� ᮧ�����
    explicit RingBuffer(std::size_t capacity)
        : cap_(capacity), data_(nullptr), head_(0), size_(0)
    {
        // �஢��塞, �� ࠧ��� ���� ����� ���
        if (cap_ == 0) {

            // �᫨ ���짮��⥫� ����� 0, ����뢠�� �᪫�祭��
            throw std::invalid_argument("RingBuffer: capacity must be > 0");
        }

        // �������᪮� �뤥����� �����
        data_ = new (std::nothrow) int[cap_];

        // �஢�ઠ 㪠��⥫�
        if (!data_) {
            throw std::runtime_error("RingBuffer: memory allocation failed");
        }

        // ������塞 ���� ��ﬨ (��� 㤮��⢠ �뢮��)
        for (std::size_t i = 0; i < cap_; ++i) data_[i] = 0;
    }

    // ����� ����஢����
    RingBuffer(const RingBuffer&) = delete;
    RingBuffer& operator=(const RingBuffer&) = delete;

    // �������� ��।����� ����, �� ������� �����
    RingBuffer(RingBuffer&& other) noexcept
        : cap_(other.cap_), data_(other.data_), head_(other.head_), size_(other.size_)
    {
        // ����塞 �ਣ����, �⮡� �� 㤠���� ������ ������
        other.data_ = nullptr;
        other.cap_ = 0;
        other.head_ = 0;
        other.size_ = 0;
    }

    RingBuffer& operator=(RingBuffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            cap_  = other.cap_;
            data_ = other.data_;
            head_ = other.head_;
            size_ = other.size_;
            other.data_ = nullptr;
            other.cap_ = 0;
            other.head_ = 0;
            other.size_ = 0;
        }
        return *this;
    }

    // �᢮������� �������᪨ �뤥������ ������
    ~RingBuffer() {
        delete[] data_;
    }

    // �����頥� ⥪�饥 �᫮ ����⮢
    std::size_t size() const {
        std::lock_guard<std::mutex> lk(m_);
        return size_;
    }

    // �����頥� ����� 񬪮��� (capacity)
    std::size_t capacity() const { return cap_; }

    // �����頥� ������ "������" - �㤠 �㤥� ����ᠭ� ᫥���饥 ���祭��
    std::size_t head_index() const {
        std::lock_guard<std::mutex> lk(m_);
        return head_;
    }

    // ������ � ����
    void write(int value) {
        std::lock_guard<std::mutex> lk(m_);
        data_[head_] = value;               // �����뢠�� ���祭��
        head_ = (head_ + 1) % cap_;         // ������� ������ (� �����⮬ � ��砫�)
        if (size_ < cap_) {
            ++size_;                        // 㢥��稢��� ࠧ���, ���� ���� �� ��������
        }
        // ��᫥ �⮣�, �᫨ ���� ��������, ���� ����� ���� ��१����뢠����
    }

    // �������� "������" �� ���� ����� �����
    RingBuffer& operator++() {
        std::lock_guard<std::mutex> lk(m_);
        head_ = (head_ + 1) % cap_;
        return *this;
    }

    // �⥭�� �����
    int at(std::size_t index) const {
        std::lock_guard<std::mutex> lk(m_);
        if (index >= size_)
            throw std::out_of_range("RingBuffer::at: index out of range");

        std::size_t tail = (head_ + cap_ - size_) % cap_;
        return data_[(tail + index) % cap_];
    }

    // ����� � ������ ��� �஢�ન �࠭��.
    int operator[](std::size_t index) const {
        std::lock_guard<std::mutex> lk(m_);
        std::size_t tail = (head_ + cap_ - size_) % cap_;
        return data_[(tail + index) % cap_];
    }

   // �뢮� ��� ����⮢
    void printAll(std::ostream& os) const {
        std::lock_guard<std::mutex> lk(m_);
        std::size_t tail = (head_ + cap_ - size_) % cap_;
        for (std::size_t i = 0; i < size_; ++i) {
            os << data_[(tail + i) % cap_];
            if (i + 1 < size_) os << ' ';
        }
    }

    // �뢮� ��������� [i1..i2]
    void printRange(std::ostream& os, std::size_t i1, std::size_t i2) const {
        std::lock_guard<std::mutex> lk(m_);
        if (i1 > i2 || i2 >= size_) {
            throw std::out_of_range("RingBuffer::printRange: bad range");
        }
        std::size_t tail = (head_ + cap_ - size_) % cap_;
        for (std::size_t i = i1; i <= i2; ++i) {
            os << data_[(tail + i) % cap_];
            if (i < i2) os << ' ';
        }
    }

    // ��ॣ�㧪� �����: �������� ������� �᫠ ��אַ � ����.
    friend std::istream& operator>>(std::istream& is, RingBuffer& rb) {
        int v;
        if (is >> v) rb.write(v);
        return is;
    }

    //  ��ॣ�㧪� �뢮��: �������� �뢮���� ᮤ�ন��� ����. 
    friend std::ostream& operator<<(std::ostream& os, const RingBuffer& rb) {
        rb.printAll(os);
        return os;
    }

    //  ��ॣ�㧪� "����" ��� ����� ���祭�� � ����.
    //  �ਬ��: rb + 42;  // ������� �᫮ 42    
    friend RingBuffer& operator+(RingBuffer& rb, int v) {
        rb.write(v);
        return rb;
    }

private:

    // ���� �����
    std::size_t cap_;   // ������� ���� (���-�� �祥�)
    int*        data_;  // 㪠��⥫� �� �������᪨� ���ᨢ
    std::size_t head_;  // ������, �㤠 �㤥� ����ᠭ� ᫥���饥 ���祭��
    std::size_t size_;  // ⥪�饥 ������⢮ ����ᠭ��� ����⮢
    mutable std::mutex m_; // ���� �� �����६������ ����㯠 �� ࠧ��� ��⮪��
};

#endif // RING_BUFFER_H
