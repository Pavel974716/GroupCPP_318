#include <iostream>
#include <string>

const int MAX_LINES = 25;
const int MAX_LENGTH = 80;

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки
void in_int(const std::string & prompt, int & var); // Функция безопасного ввода целого числа

// Сортировка по алфавиту
void sortAlphabetically(std::string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Сортировка по длине
void sortByLength(std::string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j].length() > arr[j + 1].length()) {
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Ввод одной строки с проверкой длины
bool inputOneLine(std::string & line, int lineNumber) {
    while (true) {
        line = in_string("Строка " + std::to_string(lineNumber) + ": ");

        if (line.empty()) {
            return false; // Завершение ввода
        }

        if (line.length() > MAX_LENGTH) {
            std::cout << "Ошибка: строка превышает 80 символов. Повторите ввод.\n\n";
            continue;
        }

        return true;
    }
}

// Ввод всех строк
int inputAllLines(std::string arr[]) {
    int count = 0;
    while (true) {
        std::cout << "Введите строки (максимум 25 строк, не более 80 символов каждая, пустая строка - завершение):\n\n";
        count = 0;
        for (int i = 0; i < MAX_LINES; ++i) {
            std::string line;
            if (!inputOneLine(line, i + 1)) {
                break;
            }
            arr[count++] = line;
        }

        if (count == 0) {
            std::cout << "Нет строк для сортировки. Повторите ввод.\n\n";
        } else {
            break;
        }
    }
    return count;
}

// Получение выбора пользователя
int getSortChoice() {
    int choice;
    std::cout << "\nВыберите способ сортировки:\n";
    std::cout << "1 - по алфавиту\n";
    std::cout << "2 - по длине строки\n\n";
    while (true) {
        in_int("Ваш выбор: ", choice);

        if (choice == 1 || choice == 2) {
            return choice;
        } else {
            std::cout << "Неверный выбор. Повторите ввод.\n\n";
        }
    }
}

// Главная функция Task_6
void Task_6() {
    std::string lines[MAX_LINES];

    int count = inputAllLines(lines);
    int choice = getSortChoice();

    if (choice == 1) {
        sortAlphabetically(lines, count);
    } else {
        sortByLength(lines, count);
    }

    std::cout << "\nОтсортированные строки:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << lines[i] << std::endl;
    }
}
