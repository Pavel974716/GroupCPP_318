#include <iostream>
#include <string>
#include <cctype>  // Для функций isalpha, isdigit, toupper.

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки

// Проверка правильности формата упакованной строки:
// Формат: число от 1 до 9 + одна или более букв подряд, повторяется
bool isValidCompressed(const std::string & s) {
    size_t i = 0;            // Индекс для прохода по строке
    const size_t len = s.length();

    while (i < len) {

        // Проверяем, что текущий символ цифра от '1' до '9'
        if (i >= len || !isdigit(s[i]) || s[i] == '0') {
            return false;   // Формат неверный, так как число отсутствует или равна 0
        }
        ++i; // Переходим к буквам после числа

        // Должна идти как минимум одна буква (любая, верхний или нижний регистр)
        if (i >= len || !isalpha(s[i])) {
            return false;   // Формат неверный: после числа нет букв
        }

        // Считываем подряд идущие буквы (одна или более)
        while (i < len && isalpha(s[i])) {
            ++i;
        }
        // После букв  либо конец строки, либо следующая группа начинается с числа
    }
    return true; // Все группы корректны
}

// Распаковка строки с преобразованием букв в верхний регистр
// Логика: для каждой группы число count + подряд идущие буквы,
// каждую букву повторяем count раз
std::string decompress(const std::string & compressed) {
    std::string result;
    size_t i = 0;
    const size_t len = compressed.length();

    while (i < len) {

        // Читаем число (одна цифра от '1' до '9')
        int count = compressed[i] - '0';
        ++i;

        // Считываем подряд идущие буквы, повторяя каждую count раз
        while (i < len && isalpha(compressed[i])) {

            // Добавляем в результат count раз букву в верхнем регистре
            result.append(count, std::toupper(compressed[i]));
            ++i;
        }
    }
    return result;
}

// Главная функция Task_4
void Task_4() {
    std::string compressed;

    while (true) {
        compressed = in_string("Введите упакованную строку (например, 4A5C4D): ");

        if (isValidCompressed(compressed)) {
            break;
        } else {
            std::cout << "Ошибка: строка имеет неверный формат! Попробуйте снова.\n\n";
        }
    }

    // Распаковываем и выводим результат
    std::string original = decompress(compressed);
    std::cout << "Распакованная строка: " << original << std::endl;

}
