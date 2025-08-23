#include <iostream>
#include <string>
#include <limits>

enum class ProgrEnum { Task_1, Task_2, Task_3, Task_4, Task_5 };

// ?? Ввод целого числа с проверкой
int in_int(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // Сброс ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка ввода
            std::cout << "Ошибка! Введите целое число.\n";
        } else if (value < 1 || value > 5) {
            std::cout << "Число должно быть от 1 до 5.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

// ?? Ввод строки
std::string in_string(const std::string& message) {
    std::string input;
    std::cout << message;
    std::getline(std::cin, input);
    return input;
}

// ?? Главная функция
int main() {
    std::cout << "Здравствуйте.\n";

    while (true) {
        int n = in_int("\nВведите номер задания от 1-5: ");
        ProgrEnum progrEnum = static_cast<ProgrEnum>(n - 1);

        if (progrEnum == ProgrEnum::Task_1) {
            std::cout << "Выполняется задание 1\n";
        } else if (progrEnum == ProgrEnum::Task_2) {
            std::cout << "Выполняется задание 2\n";
        } else if (progrEnum == ProgrEnum::Task_3) {
            std::cout << "Выполняется задание 3\n";
        } else if (progrEnum == ProgrEnum::Task_4) {
            std::cout << "Выполняется задание 4\n";
        } else if (progrEnum == ProgrEnum::Task_5) {
            std::cout << "Выполняется задание 5\n";
        }

        while (true) {
            std::string bukv = in_string("\nХотите ли вы выйти из программы? (y/n): ");

            if (bukv == "y" || bukv == "Y") {
                std::cout << "\nСпасибо за проверку! До свидания!\n";
                return 0;
            } else if (bukv == "n" || bukv == "N") {
                break; // Продолжить выполнение
            } else {
                std::cout << "Ответ не распознан. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }
    }

    return 0;
}
