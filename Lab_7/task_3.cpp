#include <iostream>
#include <string>
#include <stdexcept>

// Класс LoggerGuard
class LoggerGuard {
public:
    explicit LoggerGuard(const std::string& message,
                         std::ostream& out = std::cout)
        : msg_(message), out_(&out), active_(true) {}

    LoggerGuard(const LoggerGuard&) = delete;
    LoggerGuard& operator=(const LoggerGuard&) = delete;

    LoggerGuard(LoggerGuard&& other) noexcept
        : msg_(std::move(other.msg_)), out_(other.out_), active_(other.active_) {
        other.active_ = false;
    }

    LoggerGuard& operator=(LoggerGuard&& other) noexcept {
        if (this != &other) {
            flush_();
            msg_ = std::move(other.msg_);
            out_ = other.out_;
            active_ = other.active_;
            other.active_ = false;
        }
        return *this;
    }

    void dismiss() noexcept { active_ = false; }

    ~LoggerGuard() noexcept { flush_(); }

private:
    void flush_() noexcept {
        if (active_ && out_) {
            (*out_) << msg_ << '\n';
            out_->flush();
            active_ = false;
        }
    }

    std::string  msg_;
    std::ostream* out_;
    bool active_;
};

//  Функция для демонстрации работы LoggerGuard
int SomeFunction() {
    std::cout << "SomeFunction()\n";
    return 1; // возвращаем 1 (не ноль, значит продолжаем выполнение)
}

int SomeOtherFunction() {
    std::cout << "SomeOtherFunction()\n";
    return 0; // специально возвращаем 0, чтобы показать ранний выход
}

int FinalFunction() {
    std::cout << "FinalFunction()\n";
    return 42;  // нормальное завершение
}

//  Работа
int Function() {
    LoggerGuard logger("Function completed"); // Сообщение при любом выходе
    int value = 1;
    try {
        value = SomeFunction();
        if (value == 0) {
            return value; // LoggerGuard выведет сообщение
        }
        value = SomeOtherFunction();
        if (value == 0) {
            return value; // LoggerGuard опять выведет сообщение
        }
        value = FinalFunction();
    } catch (...) {
        throw; // LoggerGuard всё равно сработает
    }
    return value;
}

// Главная функция Task_3
void Task_3() {
    try {
        std::cout << "Result: " << Function() << '\n';
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
}

