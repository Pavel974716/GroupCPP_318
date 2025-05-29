#include <iostream>
#include <ctime>  // Для получения текущего времени

void in_int(const std::string & prompt, int & var); // Проверка ввода int

// Основная функция Task_5
void Task_5() {
    srand(time(0)); // Инициализация генератора случайных чисел
    int typeChoice;
    int size;

    // Ввод типа данных с проверкой
    std::cout << "Выберите тип данных:\n";
    std::cout << "1 - char\n";
    std::cout << "2 - short\n";
    std::cout << "3 - int\n";
    std::cout << "4 - float\n";
    std::cout << "5 - double\n";
    std::cout << '\n';
    while (true) {
              in_int("Введите номер типа: ", typeChoice);

             // Проверка на допустимый диапазон
             if (typeChoice < 1 ||  typeChoice > 5) {
                 std::cout << "Ошибка ввода.\n";
                 std::cout << '\n';
             } else {
               break;
             }
     }

    // Ввод количества элементов с ограничением
        const int minSize = 1;
        const int maxSize = 15;
                while (true) {
                  in_int("\nВведите количество элементов (от "  + std::to_string(minSize) +  " до " + std::to_string(maxSize) + "): ", size);

                 // Проверка на допустимый диапазон
                 if (size < minSize || size > maxSize) {
                     std::cout << "Ошибка ввода.\n";
                 } else {
                   break;
                 }
         }
    std::cout << '\n';

    switch (typeChoice) {
        case 1: {
            char* arr = new char[size];

            for (int i = 0; i < size; ++i) {
                arr[i] = static_cast<char>(rand() % 256);
            }

            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }

            std::cout << "Отсортированный char массив:\n";
            for (int i = 0; i < size; ++i) {
                std::cout << static_cast<int>(arr[i]) << ' ';
            }
            std::cout << std::endl;
            delete[] arr;
            break;
        }
        case 2: {
            short* arr = new short[size];

            for (int i = 0; i < size; ++i) {
                arr[i] = rand() % 65536 - 32768;
            }

            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if(arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }

            std::cout << "Отсортированный short массив:\n";
            for (int i = 0; i < size; ++i) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
            delete[] arr;
            break;
        }
        case 3: {
            int* arr = new int[size];

            for (int i = 0; i < size; ++i) {
                arr[i] = rand();
            }

            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                       std::swap(arr[j], arr[j + 1]);
                    }
                }
            }

            std::cout << "Отсортированный int массив:\n";
            for (int i = 0; i < size; ++i) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
            delete[] arr;
            break;
        }
        case 4: {
            float* arr = new float[size];

            for (int i = 0; i < size; ++i) {
                arr[i] = static_cast<float>(rand()) / RAND_MAX * 100.0f;
            }

            for (int i = 0; i < size - 1; ++i) {
                for (int j = 0; j < size - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                    }
                }
            }

            std::cout << "Отсортированный float массив:\n";
            for (int i = 0; i < size; ++i) {
                std::cout << arr[i] << ' ';
            }
            std::cout << std::endl;
            delete[] arr;
            break;
        }
        case 5: {
           double* arr = new double[size];

           for (int i = 0;i < size; ++i) {
               arr[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;
           }

           for (int i = 0; i < size - 1; ++i) {
               for (int j = 0; j < size -i - 1; ++j) {
                   if (arr[j] > arr[j + 1]) {
                       std::swap(arr[j], arr[j + 1]);
                   }
               }
           }

           std::cout << "Отсортированный double массив:\n";
           for (int i = 0; i < size; ++i) {
               std::cout << arr[i] << ' ';
           }
           std::cout << std::endl;
           delete[] arr;
           break;
        }
    }
}
