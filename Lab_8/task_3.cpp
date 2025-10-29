#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>

class InfoConverter {
private:
    double value_; // введённое значение
    int unit_id_; // 1..6 (bit, B, KB, MB, GB, MiB)
    double bytes_; // значение в байтах (база)

    static double pow2(int p) { return std::ldexp(1.0, p); } // 2^p, без потери точности

public:
    InfoConverter() : value_(0.0), unit_id_(2), bytes_(0.0) {}

    static void clear_stdin() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void showMenu() const {
        std::cout << "Выберите единицу измерения:\n"
                  << "  1) bit (бит)\n"
                  << "  2) B   (байт)\n"
                  << "  3) KB  (10^3 байт)\n"
                  << "  4) MB  (10^6 байт)\n"
                  << "  5) GB  (10^9 байт)\n"
                  << "  6) MiB (2^20 байт)\n";
    }

    void input() {
        // Ввод значения с проверкой
        std::cout << "Введите число (значение, от 0 до 1 000 000 000): ";
        while (true) {
            if (std::cin >> value_) {
                if (value_ >= 0 && value_ <= 1e9) break;
                std::cout << "Ошибка! Число должно быть в диапазоне от 0 до 1e9.\n\n";
            } else {
                std::cout << "Ошибка ввода. Введите число.\n\n";
            }
            clear_stdin();

            std::cout << "Введите число (значение, от 0 до 1 000 000 000): ";
        }

        // Ввод выбора единицы
        showMenu();
        std::cout << "Ваш выбор (1..6): ";
        while (!(std::cin >> unit_id_) || unit_id_ < 1 || unit_id_ > 6) {
            std::cout << "Ошибка! Введите целое число от 1 до 6.\nВаш выбор (1..6): \n";
            clear_stdin();
        }
        clear_stdin();

        toBytes();
    }

    void toBytes() {
        switch (unit_id_) {
            case 1: // bit
                bytes_ = value_ / 8.0;
                break;
            case 2: // B
                bytes_ = value_;
                break;
            case 3: // KB (10^3)
                bytes_ = value_ * 1e3;
                break;
            case 4: // MB (10^6)
                bytes_ = value_ * 1e6;
                break;
            case 5: // GB (10^9)
                bytes_ = value_ * 1e9;
                break;
            case 6: // MiB (2^20)
                bytes_ = value_ * pow2(20);
                break;
            default:
                bytes_ = value_;
        }

        // Проверка на переполнение double
        if (bytes_ > 1e18) {
            std::cout << "Предупреждение: значение слишком велико, может быть неточным.\n";
        }
    }

    void printAll() const {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "\nПреобразование:\n";
        std::cout << "----------------------------\n";
        std::cout << "Гигабайты (GB): " << (bytes_ / 1e9) << '\n';
        std::cout << "Мегабайты (MB): " << (bytes_ / 1e6) << '\n';
        std::cout << "Килобайты (KB): " << (bytes_ / 1e3) << '\n';
        std::cout << "Байты (B):      " << bytes_ << '\n';
        std::cout << "Биты (bit):     " << (bytes_ * 8.0) << '\n';
        std::cout << "Мебибайты (MiB):" << (bytes_ / pow2(20)) << '\n';
        std::cout << "----------------------------\n";
    }
};

// Главная функция Task_3
void Task_3() {
    InfoConverter conv;
    conv.input();
    conv.printAll();
}

