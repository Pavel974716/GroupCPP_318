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

// Очередь ошибок на массиве
enum class ErrCode : uint8_t {
    None = 0,
    RandInitFailed,     // не удалось инициализировать генератор случайных чисел
    InvalidRange,       // диапазон фильтра некорректен
    PrintDeviceBusy,  // устройство вывода "занято"
    DataNotReady,     // данные ещё не готовы
    Internal                // внутренняя ошибка
};

// Структура для хранения информации об ошибке
struct ErrorItem {
    ErrCode code;              // код ошибки
    const char* source;     // имя функции-источника (например, worker_fill)
    const char* stage;       // стадия конвейера: "Fill", "Filter" или "Print"
    char text[160];             // текстовое описание (фиксированный буфер)
};

// Класс кольцевой очереди для хранения ошибок
// Обеспечивает синхронизацию потоков с помощью мьютекса и condition_variable
template <size_t CAP>
class ErrorRing {
public:
    ErrorRing() : head_(0), tail_(0), count_(0) {}

    // Добавление элемента в очередь
    void push(const ErrorItem& e) {
        std::unique_lock<std::mutex> lk(m_);

        // Ждём пока в очереди есть место
        cv_not_full_.wait(lk, [this]{ return count_ < CAP; });
        buf_[tail_] = e;
        tail_ = (tail_ + 1) % CAP;
        ++count_;
        lk.unlock();
        cv_not_empty_.notify_one(); // разбудим ожидающий поток
    }

    // Извлечение элемента из очереди
    // Возвращает false, если была запрошена остановка и очередь пуста
    bool pop(ErrorItem& out, std::atomic<bool>& stopping) {
        std::unique_lock<std::mutex> lk(m_);

        // Ждём, пока появятся данные, или пока не получим сигнал "стоп"
        cv_not_empty_.wait(lk, [this, &stopping]{
            return count_ > 0 || stopping.load();
        });
        if (count_ == 0 && stopping.load()) return false; // остановка
        out = buf_[head_];
        head_ = (head_ + 1) % CAP;
        --count_;
        lk.unlock();
        cv_not_full_.notify_one(); // разбудим push
        return true;
    }

    // Сообщаем всем потокам, что нужно завершать работу
    void notify_stop() { cv_not_empty_.notify_all(); }

private:
    ErrorItem buf_[CAP];          // массив для хранения ошибок
    size_t head_, tail_, count_;  // индексы головы, хвоста и количество элементов
    std::mutex m_;
    std::condition_variable cv_not_empty_, cv_not_full_;
};

// Общие данные конвейера
static const size_t N = 1024; // размер массива данных

// Общая структура для передачи данных между потоками
struct SharedData {
    std::array<int, N> data{};                 // массив целых чисел
    bool filled   = false;                          // признак: данные заполнены
    bool filtered = false;                         // признак: данные отфильтрованы
    std::mutex mx;                                 // мьютекс для синхронизации
    std::condition_variable cv_filled;      // условие "заполнено"
    std::condition_variable cv_filtered;   // условие "отфильтровано"
};

// Утилиты
// Перевод кодов ошибок на русский
const char* err_ru(ErrCode c) {
    switch (c) {
        case ErrCode::RandInitFailed:     return "Сбой инициализации генератора случайных чисел";
        case ErrCode::InvalidRange:       return "Некорректный диапазон фильтра";
        case ErrCode::PrintDeviceBusy: return "Устройство вывода занято";
        case ErrCode::DataNotReady:    return "Данные ещё не готовы";
        case ErrCode::Internal:              return "Внутренняя ошибка";
        default:                                      return "Без кода";
    }
}

// Записываем строку в фиксированный буфер с защитой от переполнения
inline void set_text(char* dst, size_t cap, const std::string& s) {
    const size_t n = (s.size() < cap - 1) ? s.size() : (cap - 1);
    std::memcpy(dst, s.data(), n);
    dst[n] = '\0';
}

// Потоки
// Поток "заполнения" массива случайными числами
void worker_fill(SharedData& sh, ErrorRing<64>& qerr, MyMessage& log) {
    std::random_device rd;
    bool ok = (rd.entropy() > 0.0); // проверим наличие энтропии
    if (!ok) {

        // Фиксируем ошибку и используем резервный seed
        ErrorItem e{ErrCode::RandInitFailed, __func__, "Fill", {0}};
        set_text(e.text, sizeof(e.text), "Использую резервный seed (rd.entropy()==0)");
        qerr.push(e);
    }
    std::mt19937 gen(ok ? rd() : 5489u); // генератор случайных чисел
    std::uniform_int_distribution<int> dist(-500, 2000);

    {
        std::unique_lock<std::mutex> lk(sh.mx);
        for (size_t i = 0; i < N; ++i) {
            sh.data[i] = dist(gen);

            // Случайная имитация сбоя
            if ((gen() & 0xFFF) == 0) {
                ErrorItem e{ErrCode::Internal, __func__, "Fill", {0}};
                set_text(e.text, sizeof(e.text), "Случайный сбой при заполнении");
                qerr.push(e);
            }
        }
        sh.filled = true;
    }
    sh.cv_filled.notify_one(); // сигналим, что заполнено
    LOG_SVC(log, "Массив заполнен случайными числами");
}

// Поток фильтрации данных
void worker_filter(SharedData& sh, ErrorRing<64>& qerr, MyMessage& log, int lo, int hi) {
    {
        std::unique_lock<std::mutex> lk(sh.mx);
        sh.cv_filled.wait(lk, [&]{ return sh.filled; }); // ждём заполнения
    }
    if (lo > hi) {

        // Если диапазон неправильный ? фиксируем ошибку
        ErrorItem e{ErrCode::InvalidRange, __func__, "Filter", {0}};
        set_text(e.text, sizeof(e.text), "lo > hi ? переставляю местами");
        qerr.push(e);
        std::swap(lo, hi);
    }
    {
        std::unique_lock<std::mutex> lk(sh.mx);
        for (auto& v : sh.data) {
            if (v < lo || v > hi) v = 0; // оставляем только числа в диапазоне
        }
        sh.filtered = true;
    }
    sh.cv_filtered.notify_one(); // сигналим, что фильтрация завершена
    LOG_SYS(log, "Фильтрация завершена");
}

// Поток печати данных
void worker_print(SharedData& sh, ErrorRing<64>& qerr, MyMessage& log) {
    {
        std::unique_lock<std::mutex> lk(sh.mx);
        sh.cv_filtered.wait(lk, [&]{ return sh.filtered; }); // ждём фильтрации
    }
    if ((std::rand() % 50) == 0) {

        // Эмуляция ошибки "устройство занято"
        ErrorItem e{ErrCode::PrintDeviceBusy, __func__, "Print", {0}};
        set_text(e.text, sizeof(e.text), "Консоль занята (эмуляция), повтор позже");
        qerr.push(e);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // Печатаем первые 64 числа
    std::cout << "Первые 64 значения после фильтра: ";
    for (size_t i = 0; i < 64; ++i) {
        std::cout << sh.data[i] << (i + 1 == 64 ? '\n' : ' ');
    }
    LOG_SVC(log, "Печать данных выполнена");
}

// Поток логгера: ждёт ошибки в очереди и печатает их
void logger_thread(ErrorRing<64>& qerr, std::atomic<bool>& stopping, MyMessage& log) {
    ErrorItem e;
    while (qerr.pop(e, stopping)) {
        std::string line = std::string("[") + e.stage + "] " + err_ru(e.code) + ": " + e.text;
        log.log(MyMessage::Type::Error, line.c_str(), e.source);
    }
    LOG_SYS(log, "Логгер завершил работу");
}

// Главная функция Task_5
void Task_5() {
    try {
        std::srand(static_cast<unsigned>(std::time(nullptr))); // инициализация rand

        MyMessage logger(MyMessage::allEnabled()); // создаём логгер
        logger.disable(MyMessage::Type::Debug);       // убираем отладочные сообщения

        SharedData shared;                          // общие данные
        ErrorRing<64> qerr;                          // очередь ошибок
        std::atomic<bool> stopping{false};    // флаг остановки логгера

        int lo = -126, hi = 356; // диапазон фильтрации

        // Запускаем потоки
        std::thread tlog(logger_thread, std::ref(qerr), std::ref(stopping), std::ref(logger));
        std::thread t1(worker_fill,   std::ref(shared), std::ref(qerr), std::ref(logger));
        std::thread t2(worker_filter, std::ref(shared), std::ref(qerr), std::ref(logger), lo, hi);
        std::thread t3(worker_print,  std::ref(shared), std::ref(qerr), std::ref(logger));

        // Дожидаемся завершения рабочих потоков
        t1.join();
        t2.join();
        t3.join();

        // Завершаем логгер
        stopping.store(true);
        qerr.notify_stop();
        tlog.join();

        LOG_SVC(logger, "Демонстрация завершена");
    } catch (const std::system_error& e) {
        std::cerr << "System error: [" << e.code() << "] " << e.what() << '\n';
    } catch (...) {
        std::cerr << "Неизвестная ошибка\n";
    }
}


