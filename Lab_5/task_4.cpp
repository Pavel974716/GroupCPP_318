#include <iostream>
#include <string>
#include <cctype>  // Для isdigit, islower, toupper.

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки

// Проверка правильности формата упакованной строки
bool isValidCompressed(const std::string & s) {
    size_t i = 0;
    const size_t len = s.length();

    while (i < len) {
        // Проверяем, что это одна цифра от 1 до 9
        if (i >= len || s[i] < '1' || s[i] > '9') {
            return false;
        }
        i++;

        // После числа должна идти строчная буква
        if (i >= len || !islower(s[i])) {
            return false;
        }
        i++; // Переход к следующей группе
    }
    return true;
}

// Распаковка строки с преобразованием в верхний регистр
std::string decompress(const std::string & compressed) {
    std::string result;
    size_t i = 0;
    const size_t len = compressed.length();

    while (i < len) {

           // Читаем одну цифру
           const int count = compressed[i] - '0';
            i++;

            // Следующий символ ? буква
            const char letter = std::toupper(compressed[i]);
            i++;
            result.append(count, letter);
       }
    return result;
}

// Главная функция Task_4
void Task_4() {
    std::string compressed;

    // Повторяем ввод до тех пор, пока не получим корректную строку
    while (true) {
        compressed = in_string("Введите упакованную строку (например, 4a5c4d): ");


        if (isValidCompressed(compressed)) {
            break;
        } else {
            std::cout << "Ошибка: строка имеет неверный формат! Попробуйте снова.\n\n";
        }
    }

    const std::string original = decompress(compressed);
    std::cout << "Распакованная строка: " << original << std::endl;
}
