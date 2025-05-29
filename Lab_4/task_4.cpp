#include <iostream>
#include <string>
#include <vector>

void in_int(const std::string & prompt, int & var); // Проверка ввода int

// Итеративный метод
int factorialIterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result = result * i; // Полная форма умножения с присваиванием
    }
    return result;
}

// Рекурсивный метод
long long factorialRecursive(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

// Основная функция Task_4a
void Task_4a() {
    std::cout << "a)";
    int n;

    // Ввод числа с проверкой
    while (true) {
            in_int("\nВведите целое число от 0 до 12 для вычисления факториала: ", n);
            if (n < 0 || n > 12) {
                std::cout << "Ошибка ввода.\n";
            } else {
              break;
            }
      }

    // Вычисление итеративным методом
    int factIterative = factorialIterative(n);
    std::cout << "\nФакториал " << n << " (итеративно) равен: " << factIterative << '\n';

    // Вычисление рекурсивным методом
    long long factRecursive = factorialRecursive(n);
    std::cout << "Факториал " << n << " (рекурсивно) равен: " << factRecursive << std::endl;
}

// Основная функция Task_4b
void Task_4b() {
    std::cout << "\nb)";
    int n;

    // Ввод числа с проверкой
    while (true) {
            in_int("\nВведите номер числа Фибоначчи (от 0 до 5000): ", n);
            if (n < 0 || n > 5000) {
                std::cout << "Ошибка ввода.\n";
            } else {
              break;
            }
      }
        std::cout << '\n';
    if (n == 0) {
        std::cout << "Число Фибоначчи №0 равно 0" << '\n';
    } else if (n == 1) {
        std::cout << "Число Фибоначчи №1 равно 1" << '\n';
    } else {
        long long a = 0, b = 1, temp;
        for (int i = 2; i <= n; ++i) {
            temp = a + b;
            a = b;
            b = temp;
        }
        std::cout << "Число Фибоначчи №" << n << " равно " << b << std::endl;
    }
}

// Основная функция Task_4с
void Task_4c() {
    std::cout << "\nc)";
    int n;

     // Ввод числа с проверкой
     while (true) {
            in_int("\nВведите целое число для остановки (от 1 до 35): ", n);
            if (n < 1 || n > 35) {
                std::cout << "Ошибка ввода.\n";
            } else {
              break;
            }
       }
     std::cout << '\n';

    // Вектор для хранения всех строк пирамиды для определения максимальной длины
    std::vector<std::string> lines;
    size_t max_length = 0;

    int row = 1;
    bool stop = false;
    while (!stop) {
        int sum = 0;
        std::string line_numbers;

        // Формируем строку с числами
        for (int i = row; i >= 1; --i) {
            line_numbers += std::to_string(i) + " ";
            if (i == n) {
                stop = true;
            }
            sum += i;
        }
        line_numbers += std::to_string(sum);

        lines.push_back(line_numbers);
        if (sum == n) {
            break;
        }
        ++row;
    }

    // Находим максимальную длину строки
    for (const auto & line : lines) {
        if (line.length() > max_length) { // Сравнение теперь между size_t
            max_length = line.length();
        }
    }

    // Выводим пирамиду с центрированием
    for (const auto & line : lines) {
        int padding = static_cast<int>((max_length - line.length()) / 2);
        for (int i = 0; i < padding; ++i)
        std::cout << " ";
        std::cout << line << std::endl;
    }
}

