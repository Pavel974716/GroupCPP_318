#include <iostream>
#include <random> // Для стандартного генератора случайных чисел
#include <ctime>  // Для получения текущего времени

//  Реализация userRandom Task_1
int userRandom(int min, int max) {
    static unsigned int seed = static_cast<unsigned int>(time(0)); // Установка начального значения
    seed = (214013 * seed + 2531011); // Простой линейный конгруэнтный генератор
    return (seed >> 16) % (max - min + 1) + min; // Генерация числа в диапазоне [min, max]
}

// Функция для поиска минимума и максимума в массиве
void findMinMax(const int* arr, int size, int& minVal, int& maxVal) {
    minVal = arr[0];
    maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
}

// Основная функция Task_1
void Task_1() {
    const int size = 10;
    int arrayStd[size];   // Массив для стандартного генератора
    int arrayCustom[size]; // Массив для userRandom

    // Инициализация стандартного генератора
    std::mt19937 mt(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<int> dist(1, 100);

    // Заполнение массивов
    for (int i = 0; i < size; ++i) {
        arrayStd[i] = dist(mt);                  // Стандартный генератор
        arrayCustom[i] = userRandom(1, 100);   // Мой генератор
    }

    // Находим и выводим минимум и максимум для массива стандартных чисел
    int minStd, maxStd;
    findMinMax(arrayStd, size, minStd, maxStd);
    std::cout << "Массив стандартного генератора: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arrayStd[i] << " ";
    }
    std::cout << "\nМинимум: " << minStd << "\nМаксимум: " << maxStd << std::endl;
    std::cout << '\n';

    // Находим и выводим минимум и максимум для массива userRandom
    int minCustom, maxCustom;
    findMinMax(arrayCustom, size, minCustom, maxCustom);
    std::cout << "Массив придуманного генератора: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arrayCustom[i] << " ";
    }
    std::cout << "\nМинимум: " << minCustom << "\nМаксимум: " << maxCustom << std::endl;
}
