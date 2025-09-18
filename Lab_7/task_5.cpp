#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <mutex>
#include <random>
#include <thread>
#include <iostream>

#include "MyMessage.h"

// ��।� �訡�� �� ���ᨢ�
enum class ErrCode : uint8_t {
    None = 0,
    RandInitFailed,     // �� 㤠���� ���樠����஢��� ������� ��砩��� �ᥫ
    InvalidRange,       // �������� 䨫��� �����४⥭
    PrintDeviceBusy,  // ���ன�⢮ �뢮�� "�����"
    DataNotReady,     // ����� ��� �� ��⮢�
    Internal                // ����७��� �訡��
};

// ������� ��� �࠭���� ���ଠ樨 �� �訡��
struct ErrorItem {
    ErrCode code;              // ��� �訡��
    const char* source;     // ��� �㭪樨-���筨�� (���ਬ��, worker_fill)
    const char* stage;       // �⠤�� ��������: "Fill", "Filter" ��� "Print"
    char text[160];             // ⥪�⮢�� ���ᠭ�� (䨪�஢���� ����)
};

// ����� ����楢�� ��।� ��� �࠭���� �訡��
// ���ᯥ稢��� ᨭ�஭����� ��⮪�� � ������� ���⥪� � condition_variable
template <size_t CAP>
class ErrorRing {
public:
    ErrorRing() : head_(0), tail_(0), count_(0) {}

    // ���������� ����� � ��।�
    void push(const ErrorItem& e) {
        std::unique_lock<std::mutex> lk(m_);

        // ��� ���� � ��।� ���� ����
        cv_not_full_.wait(lk, [this]{ return count_ < CAP; });
        buf_[tail_] = e;
        tail_ = (tail_ + 1) % CAP;
        ++count_;
        lk.unlock();
        cv_not_empty_.notify_one(); // ࠧ�㤨� ������騩 ��⮪
    }

    // �����祭�� ����� �� ��।�
    // �����頥� false, �᫨ �뫠 ����襭� ��⠭���� � ��।� ����
    bool pop(ErrorItem& out, std::atomic<bool>& stopping) {
        std::unique_lock<std::mutex> lk(m_);

        // ���, ���� ������� �����, ��� ���� �� ����稬 ᨣ��� "�⮯"
        cv_not_empty_.wait(lk, [this, &stopping]{
            return count_ > 0 || stopping.load();
        });
        if (count_ == 0 && stopping.load()) return false; // ��⠭����
        out = buf_[head_];
        head_ = (head_ + 1) % CAP;
        --count_;
        lk.unlock();
        cv_not_full_.notify_one(); // ࠧ�㤨� push
        return true;
    }

    // ����頥� �ᥬ ��⮪��, �� �㦭� �������� ࠡ���
    void notify_stop() { cv_not_empty_.notify_all(); }

private:
    ErrorItem buf_[CAP];          // ���ᨢ ��� �࠭���� �訡��
    size_t head_, tail_, count_;  // ������� ������, 墮�� � ������⢮ ����⮢
    std::mutex m_;
    std::condition_variable cv_not_empty_, cv_not_full_;
};

// ��騥 ����� ��������
static const size_t N = 1024; // ࠧ��� ���ᨢ� ������

// ���� ������� ��� ��।�� ������ ����� ��⮪���
struct SharedData {
    std::array<int, N> data{};                 // ���ᨢ 楫�� �ᥫ
    bool filled   = false;                          // �ਧ���: ����� ���������
    bool filtered = false;                         // �ਧ���: ����� ��䨫��஢���
    std::mutex mx;                                 // ���⥪� ��� ᨭ�஭���樨
    std::condition_variable cv_filled;      // �᫮��� "���������"
    std::condition_variable cv_filtered;   // �᫮��� "��䨫��஢���"
};

// �⨫���
// ��ॢ�� ����� �訡�� �� ���᪨�
const char* err_ru(ErrCode c) {
    switch (c) {
        case ErrCode::RandInitFailed:     return "���� ���樠����樨 ������� ��砩��� �ᥫ";
        case ErrCode::InvalidRange:       return "�����४�� �������� 䨫���";
        case ErrCode::PrintDeviceBusy: return "���ன�⢮ �뢮�� �����";
        case ErrCode::DataNotReady:    return "����� ��� �� ��⮢�";
        case ErrCode::Internal:              return "����७��� �訡��";
        default:                                      return "��� ����";
    }
}

// �����뢠�� ��ப� � 䨪�஢���� ���� � ���⮩ �� ��९�������
inline void set_text(char* dst, size_t cap, const std::string& s) {
    const size_t n = (s.size() < cap - 1) ? s.size() : (cap - 1);
    std::memcpy(dst, s.data(), n);
    dst[n] = '\0';
}

// ��⮪�
// ��⮪ "����������" ���ᨢ� ��砩�묨 �᫠��
void worker_fill(SharedData& sh, ErrorRing<64>& qerr, MyMessage& log) {
    std::random_device rd;
    bool ok = (rd.entropy() > 0.0); // �஢�ਬ ����稥 ��ய��
    if (!ok) {

        // �����㥬 �訡�� � �ᯮ��㥬 १�ࢭ� seed
        ErrorItem e{ErrCode::RandInitFailed, __func__, "Fill", {0}};
        set_text(e.text, sizeof(e.text), "�ᯮ���� १�ࢭ� seed (rd.entropy()==0)");
        qerr.push(e);
    }
    std::mt19937 gen(ok ? rd() : 5489u); // ������� ��砩��� �ᥫ
    std::uniform_int_distribution<int> dist(-500, 2000);

    {
        std::unique_lock<std::mutex> lk(sh.mx);
        for (size_t i = 0; i < N; ++i) {
            sh.data[i] = dist(gen);

            // ���砩��� ������ ᡮ�
            if ((gen() & 0xFFF) == 0) {
                ErrorItem e{ErrCode::Internal, __func__, "Fill", {0}};
                set_text(e.text, sizeof(e.text), "���砩�� ᡮ� �� ����������");
                qerr.push(e);
            }
        }
        sh.filled = true;
    }
    sh.cv_filled.notify_one(); // ᨣ�����, �� ���������
    LOG_SVC(log, "���ᨢ �������� ��砩�묨 �᫠��");
}

// ��⮪ 䨫���樨 ������
void worker_filter(SharedData& sh, ErrorRing<64>& qerr, MyMessage& log, int lo, int hi) {
    {
        std::unique_lock<std::mutex> lk(sh.mx);
        sh.cv_filled.wait(lk, [&]{ return sh.filled; }); // ��� ����������
    }
    if (lo > hi) {

        // �᫨ �������� ���ࠢ���� ? 䨪��㥬 �訡��
        ErrorItem e{ErrCode::InvalidRange, __func__, "Filter", {0}};
        set_text(e.text, sizeof(e.text), "lo > hi ? ����⠢��� ���⠬�");
        qerr.push(e);
        std::swap(lo, hi);
    }
    {
        std::unique_lock<std::mutex> lk(sh.mx);
        for (auto& v : sh.data) {
            if (v < lo || v > hi) v = 0; // ��⠢�塞 ⮫쪮 �᫠ � ���������
        }
        sh.filtered = true;
    }
    sh.cv_filtered.notify_one(); // ᨣ�����, �� 䨫����� �����襭�
    LOG_SYS(log, "�������� �����襭�");
}

// ��⮪ ���� ������
void worker_print(SharedData& sh, ErrorRing<64>& qerr, MyMessage& log) {
    {
        std::unique_lock<std::mutex> lk(sh.mx);
        sh.cv_filtered.wait(lk, [&]{ return sh.filtered; }); // ��� 䨫���樨
    }
    if ((std::rand() % 50) == 0) {

        // ������ �訡�� "���ன�⢮ �����"
        ErrorItem e{ErrCode::PrintDeviceBusy, __func__, "Print", {0}};
        set_text(e.text, sizeof(e.text), "���᮫� ����� (�����), ����� �����");
        qerr.push(e);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // ���⠥� ���� 64 �᫠
    std::cout << "���� 64 ���祭�� ��᫥ 䨫���: ";
    for (size_t i = 0; i < 64; ++i) {
        std::cout << sh.data[i] << (i + 1 == 64 ? '\n' : ' ');
    }
    LOG_SVC(log, "����� ������ �믮�����");
}

// ��⮪ ������: ���� �訡�� � ��।� � ���⠥� ��
void logger_thread(ErrorRing<64>& qerr, std::atomic<bool>& stopping, MyMessage& log) {
    ErrorItem e;
    while (qerr.pop(e, stopping)) {
        std::string line = std::string("[") + e.stage + "] " + err_ru(e.code) + ": " + e.text;
        log.log(MyMessage::Type::Error, line.c_str(), e.source);
    }
    LOG_SYS(log, "������ �����訫 ࠡ���");
}

// ������� �㭪�� Task_5
void Task_5() {
    try {
        std::srand(static_cast<unsigned>(std::time(nullptr))); // ���樠������ rand

        MyMessage logger(MyMessage::allEnabled()); // ᮧ��� ������
        logger.disable(MyMessage::Type::Debug);       // 㡨ࠥ� �⫠���� ᮮ�饭��

        SharedData shared;                          // ��騥 �����
        ErrorRing<64> qerr;                          // ��।� �訡��
        std::atomic<bool> stopping{false};    // 䫠� ��⠭���� ������

        int lo = -126, hi = 356; // �������� 䨫���樨

        // ����᪠�� ��⮪�
        std::thread tlog(logger_thread, std::ref(qerr), std::ref(stopping), std::ref(logger));
        std::thread t1(worker_fill,   std::ref(shared), std::ref(qerr), std::ref(logger));
        std::thread t2(worker_filter, std::ref(shared), std::ref(qerr), std::ref(logger), lo, hi);
        std::thread t3(worker_print,  std::ref(shared), std::ref(qerr), std::ref(logger));

        // ���������� �����襭�� ࠡ��� ��⮪��
        t1.join();
        t2.join();
        t3.join();

        // �����蠥� ������
        stopping.store(true);
        qerr.notify_stop();
        tlog.join();

        LOG_SVC(logger, "���������� �����襭�");
    } catch (const std::system_error& e) {
        std::cerr << "System error: [" << e.code() << "] " << e.what() << '\n';
    } catch (...) {
        std::cerr << "�������⭠� �訡��\n";
    }
}


