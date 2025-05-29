#include <iostream>
#include <string>

// Функция для обмена двух символов
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// Функция перестановок
void permute(std::string & str, int l, int r) {
    if (l == r) {
        std::cout << str << std::endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]); // Используем функцию swap
            permute(str, l + 1, r); // Рекурсивно вызываем для следующего элемента
            swap(str[l], str[i]); // Возвращаем обратно для следующей итерации
        }
    }
}

// Основная функция Task_7
void Task_7() {
    std::string phases = "UVW"; // Строка с фазами
    int n = phases.size();
    permute(phases, 0, n - 1); // Генерация перестановок
}
