#include <iostream>
#include <cstring>  // Для strncpy
#include <sstream>  // Для istringstream
#include <cctype>   // Для isdigit
#include <climits>  // Для INT_MAX и INT_MIN

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки
void in_int(const std::string & prompt, int & var); // Функция безопасного ввода целого числа

// Проверка, является ли строка целым числом, с учетом переполнения
bool isValidIntString(const std::string & str) {
    if (str.empty()) return false;

    size_t i = 0;
    bool isNegative = false;

    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    if (i == str.length()) return false;

    for (size_t j = i; j < str.length(); ++j) {
        if (!isdigit(str[j])) return false;
    }

    long long result = 0;
    i = 0;
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
    }

    for (; i < str.length(); ++i) {
        result = result * 10 + (str[i] - '0');
        if (!isNegative && result > INT_MAX) return false;
        if (isNegative && -result < INT_MIN) return false;
    }

    return true;
}

// Подсчёт чисел в строке и выбор первого валидного
bool extractFirstValidInt(const std::string & input, std::string & outNumber, int & count) {
    std::istringstream iss(input);
    std::string word;
    count = 0;
    outNumber.clear();

    while (iss >> word) {
        if (isValidIntString(word)) {
            count++;
            if (outNumber.empty()) {
                outNumber = word;
            }
        }
    }

    if (count > 0 && count <= 10) {
        return true;
    } else {
        return false;
    }
}

// Преобразование числа в строку
void intToCString(int num, char *buffer) {
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    bool isNegative = false;
    int i = 0;

    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    while (num > 0) {
        buffer[i] = '0' + (num % 10);
        num = num / 10;
        i++;
    }

    if (isNegative) {
        buffer[i] = '-';
        i++;
    }

    buffer[i] = '\0';

    // Реверс
    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }
}

// Преобразование строки в число
int cStringToInt(const char *str) {
    int result = 0;
    int i = 0;
    bool isNegative = false;

    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    if (isNegative) {
        return -result;
    } else {
        return result;
    }
}

// Главная функция Task_7
void Task_7() {
    const int SIZE = 100;
    char buffer[SIZE];

    int number;
    in_int("Введите целое число (не больше 10 чисел): ", number);

    intToCString(number, buffer);
    std::cout << "Результат (число в строку): " << buffer << '\n';

    std::string input, extracted;
    int count = 0;
    bool valid;

    do {
        input = in_string("\nВведите строку с не более чем 10 целыми числами: ");
        valid = extractFirstValidInt(input, extracted, count);
        if (!valid) {
            if (count == 0) {
                std::cout << "Ошибка: в строке не найдено ни одного допустимого целого числа.\n";
            } else {
                std::cout << "Ошибка: в строке больше 10 допустимых целых чисел.\n";
            }
        }
    } while (!valid);

    std::strncpy(buffer, extracted.c_str(), SIZE - 1);
    buffer[SIZE - 1] = '\0';

    int parsed = cStringToInt(buffer);
    std::cout << "Результат (первое число из строки): " << parsed << std::endl;
}
