#include <iostream>

//  Функция для обмена местами
void swapEvenOdd(char *arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        char temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

// Основная функция Task_9
void Task_9() {
    char arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    std::cout << "Исходные данные массива:\n";
    for (int i = 0; i < 12; i++) {
        std::cout << "ячейка " << i << ": " << static_cast<int>(arr[i]) << std::endl;
    }

    swapEvenOdd(arr, 12);

    std::cout << "\nДанные после работы функции:\n";
    for (int i = 0; i < 12; i++) {
        std::cout << "ячейка " << i << ": " << static_cast<int>(arr[i]) << std::endl;
    }
}
