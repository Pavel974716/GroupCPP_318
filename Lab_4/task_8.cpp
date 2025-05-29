#include <iostream>
#include <functional>

void in_int(const std::string & prompt, int & var);

// Определяем логические функции
int logical_and(int a, int b) {
    return a & b;
}

int logical_or(int a, int b) {
    return a | b;
}

int logical_xor(int a, int b) {
    return a ^ b;
}

// Функция для выполнения логической операции
int perform_operation(int a, int b, std::function<int(int, int)> operation) {
    return operation(a, b);
}

// Функция для выполнения логической операции с указателем на функцию
int perform_operation_with_pointer(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// Основная функция Task_8
void Task_8() {
    const int MIN_VALUE = 0; // Минимальное значение для ввода
    const int MAX_VALUE = 100; // Максимальное значение для ввода
    int choice;
    int num1, num2;

    std::cout << "Выберите операцию:\n";
    std::cout << "1 - И\n";
    std::cout << "2 - ИЛИ\n";
    std::cout << "3 - XOR\n";

    in_int("Введите номер операции (1-3): ", choice); // Ввод выбора операции

    // Проверка корректности выбора операции
    while (choice < 1 || choice > 3) {
        std::cout << "Ошибка ввода.\n";
        in_int("Введите номер операции (1-3): ", choice);
    }

    in_int("Введите первое целое число в диапазоне [0, 100]: ", num1); // Ввод первого числа
    while (num1 < MIN_VALUE || num1 > MAX_VALUE) {
        std::cout << "Ошибка ввода.\n";
        in_int("Введите первое целое число в диапазоне [0, 100]: ", num1);
    }

    in_int("Введите второе целое число в диапазоне [0, 100]: ", num2); // Ввод второго числа
    while (num2 < MIN_VALUE || num2 > MAX_VALUE) {
        std::cout << "Ошибка ввода.\n";
        in_int("Введите второе целое число в диапазоне [0, 100]: ", num2);
    }

    switch (choice) {
        case 1: {
            // Используем std::function
            std::function<int(int, int)> operation = logical_and;
            std::cout << "Результат: " << perform_operation(num1, num2, operation) << '\n';
            // Используем указатель на функцию
            std::cout << "Результат (указатель): " << perform_operation_with_pointer(num1, num2, logical_and) << std::endl;
            break;
        }
        case 2: {
            // Используем std::function
            std::function<int(int, int)> operation = logical_or;
            std::cout << "Результат: " << perform_operation(num1, num2, operation) << '\n';
            // Используем указатель на функцию
            std::cout << "Результат (указатель): " << perform_operation_with_pointer(num1, num2, logical_or) << std::endl;
            break;
        }
        case 3: {
            // Используем std::function
            std::function<int(int, int)> operation = logical_xor;
            std::cout << "Результат: " << perform_operation(num1, num2, operation) << '\n';
            // Используем указатель на функцию
            std::cout << "Результат (указатель): " << perform_operation_with_pointer(num1, num2, logical_xor) << std::endl;
            break;
        }
    }
}
