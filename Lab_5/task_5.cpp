#include <iostream>
#include <string>

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки

// Главная функция Task_5
void Task_5() {
    std::string input;
    input = in_string("Введите строку (макс. 100 символов): ");

    // Подсчёт введённых символов
    size_t inputLength = input.length();
    std::cout << "\nВведено символов: " << inputLength << '\n';

    // Ограничим длину строки до 100 символов
    if (inputLength > 100) {
        input = input.substr(0, 100);
        std::cout << "Строка обрезана до 100 символов." << '\n';
    }

    // Заменяем табуляции на пробелы
    for (char & ch : input) {
        if (ch == '\t') {
            ch = ' ';
        }
    }

    // Удаляем повторяющиеся пробелы
    std::string result;
    bool prev_space = false;

    for (char ch : input) {
        if (ch == ' ') {
            if (!prev_space) {
                result += ch;
                prev_space = true;
            }
        } else {
            result += ch;
            prev_space = false;
        }
    }

    // Удаляем начальные и конечные пробелы
    size_t first = result.find_first_not_of(' ');
    size_t last = result.find_last_not_of(' ');
    if (first != std::string::npos) {
        result = result.substr(first, last - first + 1);
    } else {
        result = ""; // Cтрока из одних пробелов
    }

    std::cout << "Результат: \"" << result << "\"" << std::endl;
}
