#include <iostream>
#include <iomanip> // Библиотека для std::setw, что бы установить ширину матрицы
#include <cstdlib> // Для srand() и rand()
#include <ctime> // Для получения текущего времени

// Основная функция Task_2a
void Task_2a() {
    const int size = 5;
    int matrixA[size][size];

    // Заполнение матрицы: единицы на диагонали, нули ? в остальных местах
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j)
                matrixA[i][j] = 1;
            else
                matrixA[i][j] = 0;
        }
    }

    // Вывод матрицы
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrixA[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Основная функция Task_2b
void Task_2b() {
    const int SIZE = 8; // Объявляем размер матрицы

        // Инициализация генератора случайных чисел
        std::srand(std::time(nullptr));

        int matrixB[SIZE][SIZE];

        // Заполнение матрицы псевдослучайными числами от -15 до 15
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                matrixB[i][j] = std::rand() % 31 - 15; // Диапазон: -15..15
            }
        }

        // Вывод матрицы с выравниванием
            for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                std::cout << std::setw(5) << matrixB[i][j];
            }
            std::cout << '\n' << '\n';
        }

        // Вычисление суммы элементов выше главной диагонали
        int sumAboveMainDiagonal = 0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = i + 1; j < SIZE; ++j) { // j > i, чтобы быть выше диагонали
                sumAboveMainDiagonal += matrixB[i][j];
            }
        }

        // Вывод результата
        std::cout << "Сумма элементов, лежащих выше главной диагонали: "
                  << sumAboveMainDiagonal << std::endl;        
}
