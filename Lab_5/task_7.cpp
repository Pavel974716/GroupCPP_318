#include <iostream>
#include <cstring>
#include <cctype>
#include <climits>

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки
void in_int(const std::string & prompt, int & var); // Функция безопасного ввода целого числа

// Проверка, что строка ? это корректное целое число (без мусора, без переполнения)
bool isValidIntegerString(const std::string &str) {
    if (str.empty()) return false; // пустая строка ? не число

    size_t i = 0;
    bool isNegative = false;

    // Обработка знака
    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    if (i == str.length()) return false; // только знак без цифр

    // Проверка, что все оставшиеся символы ? цифры
    for (size_t j = i; j < str.length(); ++j) {
        if (!isdigit(static_cast<unsigned char>(str[j]))) return false;
    }

    // Проверка переполнения через long long
    long long result = 0;
    i = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    for (; i < str.length(); ++i) {
        result = result * 10 + (str[i] - '0');
        if (!isNegative && result > INT_MAX) return false;   // переполнение положительного
        if (isNegative && -result < INT_MIN) return false;   // переполнение отрицательного
    }

    return true;
}

// Проверка, что символ ? цифра
bool isCharDigit(char c) {
    return c >= '0' && c <= '9';
}

// Преобразование C-строки в int с проверкой переполнения
bool stringToInt(const char *str, int &out) {
    if (!str || *str == '\0') return false; // null или пустая строка

    long long result = 0;
    int i = 0;
    bool isNegative = false;

    // Обработка знака
    if (str[i] == '-') {
        isNegative = true;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    if (str[i] == '\0') return false; // только знак ? ошибка

    // Считываем цифры
    while (str[i] != '\0') {
        if (!isCharDigit(str[i])) return false; // не цифра ? ошибка

        result = result * 10 + (str[i] - '0');
        if (!isNegative && result > INT_MAX) return false; // переполнение
        if (isNegative && -result < INT_MIN) return false; // переполнение

        i++;
    }

    out = isNegative ? -static_cast<int>(result) : static_cast<int>(result);
    return true;
}

// Преобразование int в C-строку
void intToCString(int num, char *buffer) {
    if (!buffer) return;

    if (num == 0) { // отдельный случай для нуля
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    bool isNegative = false;
    unsigned int unum;
    int i = 0;

    // Преобразуем к unsigned для корректной обработки INT_MIN
    if (num < 0) {
        isNegative = true;
        unum = static_cast<unsigned int>(-(long long)num);
    } else {
        unum = static_cast<unsigned int>(num);
    }

    // Записываем цифры в обратном порядке
    while (unum > 0) {
        buffer[i++] = '0' + (unum % 10);
        unum /= 10;
    }

    // Если было отрицательное ? добавляем '-'
    if (isNegative) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    // Реверс строки
    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }
}

// Поиск первого корректного числа в строке (префиксный метод)
bool findFirstInteger(const std::string &input, std::string &outNumber, int &count) {
    count = 0;
    size_t i = 0;

    while (i < input.length()) {

        // Пропускаем всё, что не цифра и не знак
        if (input[i] != '+' && input[i] != '-' && !isCharDigit(input[i])) {
            i++;
            continue;
        }

        size_t start = i;

        // Если есть знак, проверяем, что за ним идёт цифра
        if (input[i] == '+' || input[i] == '-') {
            i++;
            if (i >= input.length() || !isCharDigit(input[i])) {
                continue; // не число ? идём дальше
            }
        }

        // Считываем цифры
        while (i < input.length() && isCharDigit(input[i])) {
            i++;
        }

        // Получили подстроку, которая может быть числом
        std::string numberStr = input.substr(start, i - start);

        // Проверка числа на корректность
        if (isValidIntegerString(numberStr)) {
            outNumber = numberStr;
            count = 1; // нашли одно число
            return true; // сразу выходим
        }
    }
    return false; // не нашли ни одного корректного числа
}

// Главная функция Task_7
void Task_7() {
    const int SIZE = 100;
    char buffer[SIZE];

    // Ввод числа и преобразование в строку
    int number;
    in_int("Введите целое положительное число (не больше 10 символов): ", number);

    intToCString(number, buffer);
    std::cout << "Результат (число в строку): " << buffer << '\n';

    // Ввод строки и поиск первого числа
    std::string input, extracted;
    int count = 0;
    bool valid;

    do {
        input = in_string("\nВведите строку с числами (каждое число не больше 10 символов): ");
        valid = findFirstInteger(input, extracted, count);
        if (!valid) {
            std::cout << "Ошибка: в строке не найдено допустимого целого числа.\n";
        }
    } while (!valid);

    // Конвертация найденного числа в int
    std::strncpy(buffer, extracted.c_str(), SIZE - 1);
    buffer[SIZE - 1] = '\0';

    int parsed;
    if (stringToInt(buffer, parsed)) {
        std::cout << "Результат (первое число из строки): " << parsed << std::endl;
    } else {
        std::cout << "Ошибка преобразования числа из строки.\n";
    }
}
