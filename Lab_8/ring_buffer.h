#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <atomic>
#include <mutex>
#include <new>

// Кольцевой буфер
class RingBuffer {
public:

    // explicit - запрещает неявное преобразование типов при создании
    explicit RingBuffer(std::size_t capacity)
        : cap_(capacity), data_(nullptr), head_(0), size_(0)
    {
        // Проверяем, что размер буфера больше нуля
        if (cap_ == 0) {

            // Если пользователь задал 0, выбрасываем исключение
            throw std::invalid_argument("RingBuffer: capacity must be > 0");
        }

        // Динамическое выделение памяти
        data_ = new (std::nothrow) int[cap_];

        // Проверка указателя
        if (!data_) {
            throw std::runtime_error("RingBuffer: memory allocation failed");
        }

        // Заполняем буфер нулями (для удобства вывода)
        for (std::size_t i = 0; i < cap_; ++i) data_[i] = 0;
    }

    // Запрет копирования
    RingBuffer(const RingBuffer&) = delete;
    RingBuffer& operator=(const RingBuffer&) = delete;

    // Позволяет передавать буфер, не копируя данные
    RingBuffer(RingBuffer&& other) noexcept
        : cap_(other.cap_), data_(other.data_), head_(other.head_), size_(other.size_)
    {
        // Обнуляем оригинал, чтобы не удалить память дважды
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

    // Освобождает динамически выделенную память
    ~RingBuffer() {
        delete[] data_;
    }

    // Возвращает текущее число элементов
    std::size_t size() const {
        std::lock_guard<std::mutex> lk(m_);
        return size_;
    }

    // Возвращает общую ёмкость (capacity)
    std::size_t capacity() const { return cap_; }

    // Возвращает индекс "головы" - куда будет записано следующее значение
    std::size_t head_index() const {
        std::lock_guard<std::mutex> lk(m_);
        return head_;
    }

    // Запись в буфер
    void write(int value) {
        std::lock_guard<std::mutex> lk(m_);
        data_[head_] = value;               // записываем значение
        head_ = (head_ + 1) % cap_;         // двигаем голову (с возвратом в начало)
        if (size_ < cap_) {
            ++size_;                        // увеличиваем размер, пока буфер не заполнен
        }
        // После этого, если буфер заполнен, старые данные будут перезаписываться
    }

    // Сдвигает "голову" на один элемент вперёд
    RingBuffer& operator++() {
        std::lock_guard<std::mutex> lk(m_);
        head_ = (head_ + 1) % cap_;
        return *this;
    }

    // Чтение элемента
    int at(std::size_t index) const {
        std::lock_guard<std::mutex> lk(m_);
        if (index >= size_)
            throw std::out_of_range("RingBuffer::at: index out of range");

        std::size_t tail = (head_ + cap_ - size_) % cap_;
        return data_[(tail + index) % cap_];
    }

    // Доступ к элементу без проверки границ.
    int operator[](std::size_t index) const {
        std::lock_guard<std::mutex> lk(m_);
        std::size_t tail = (head_ + cap_ - size_) % cap_;
        return data_[(tail + index) % cap_];
    }

   // Вывод всех элементов
    void printAll(std::ostream& os) const {
        std::lock_guard<std::mutex> lk(m_);
        std::size_t tail = (head_ + cap_ - size_) % cap_;
        for (std::size_t i = 0; i < size_; ++i) {
            os << data_[(tail + i) % cap_];
            if (i + 1 < size_) os << ' ';
        }
    }

    // Вывод диапазона [i1..i2]
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

    // Перегрузка ввода: позволяет вводить числа прямо в буфер.
    friend std::istream& operator>>(std::istream& is, RingBuffer& rb) {
        int v;
        if (is >> v) rb.write(v);
        return is;
    }

    //  Перегрузка вывода: позволяет выводить содержимое буфера. 
    friend std::ostream& operator<<(std::ostream& os, const RingBuffer& rb) {
        rb.printAll(os);
        return os;
    }

    //  Перегрузка "плюса" для записи значения в буфер.
    //  Пример: rb + 42;  // добавит число 42    
    friend RingBuffer& operator+(RingBuffer& rb, int v) {
        rb.write(v);
        return rb;
    }

private:

    // Поля класса
    std::size_t cap_;   // емкость буфера (кол-во ячеек)
    int*        data_;  // указатель на динамический массив
    std::size_t head_;  // индекс, куда будет записано следующее значение
    std::size_t size_;  // текущее количество записанных элементов
    mutable std::mutex m_; // защита от одновременного доступа из разных потоков
};

#endif // RING_BUFFER_H
