#include <iostream>

void in_int(const std::string & prompt, int & var); // Проверка ввода int
void in_double(const std::string & prompt, double & var); // Проверка ввода double
void in_char(const std::string & prompt, char & var); // Проверка ввода char

// Основная функция Task_6a
void Task_6a() {
    std::cout << "a)\n";
    int m;
    double fx;
    char cht;

    // Ввод данных с проверкой
    in_int("Введите целое число m: ", m);
    in_double("Введите число с плавающей точкой fx: ", fx);
    in_char("Введите символ cht: ", cht);

    // Объявляем указатели
    int* p_m = &m;
    double* p_fx = &fx;
    char* p_cht = &cht;

    // Вывод результатов
    std::cout << "\nУказатель: продемонстрировать использование операторов & и *:\n";
    std::cout << "-------------------------------------------------- ------\n";
    std::cout << "m = " << m << '\n';
    std::cout << "fx = " << fx << '\n';
    std::cout << "cht = " << cht << std::endl;

    // Использование & и *
    std::cout << "\nИспользование & оператор:\n";
    std::cout << "-----------------------\n";
    std::cout << "адрес m = " << static_cast<void*>(p_m) << '\n';
    std::cout << "адрес fx = " << static_cast<void*>(p_fx) << '\n';
    std::cout << "адрес cht = " << static_cast<void*>(p_cht) << std::endl;

    std::cout << "\nИспользуя операторы & и *:\n";
    std::cout << "-----------------------------\n";
    std::cout << "значение по адресу m = " << *p_m << '\n';
    std::cout << "значение по адресу fx = " << *p_fx << '\n';
    std::cout << "значение по адресу cht = " << *p_cht << std::endl;

    // Использование только переменной указателя
    int* ptr_m = p_m;
    double* ptr_fx = p_fx;
    char* ptr_cht = p_cht;

    std::cout << "\nИспользованием только переменной указателя:\n";
    std::cout << "----------------------------------\n";

    std :: cout <<  "адрес m = "<< static_cast<void*>(ptr_m) << '\n';
    std :: cout <<  "адрес fx = "<< static_cast<void*>(ptr_fx) << '\n';
    std :: cout <<  "адрес cht= "<< static_cast<void*>(ptr_cht) << std::endl;

    // Использование только оператора указателя
    std :: cout << "\nИспользование только оператора указателя:\n";
    std :: cout << "----------------------------------\n";

    std :: cout << "значение по адресу m= " << *ptr_m << '\n';
    std :: cout << "значение по адресу fx= " << *ptr_fx << '\n';
    std :: cout << "значение по адресу cht= " << *ptr_cht << std::endl;
}

// Основная функция Task_6b
void Task_6b() {
    std::cout << "\nb)\n";
    int n;

        // Запрашиваем у пользователя количество элементов
        while (true) {
            in_int("Введите количество элементов (от 1 до 10): ", n);
            if (n < 1 || n > 10) {
                std::cout << "Ошибка ввода.\n";
                std::cout << '\n';
            } else {
                break; // Ввод корректен, выходим из цикла
            }
        }

        int arr[n]; // Объявляем массив размером n
        int* ptr = arr; // Указатель на первый элемент массива

        // Заполняем массив элементами
        std::cout << "\nВведите " << n << " элементов:\n";
        for (int i = 0; i < n; i++) {
            in_int("Элемент " + std::to_string(i + 1) + ": ", arr[i]);
        }

        // Печатаем элементы массива с помощью указателя и индексации
        std::cout << "\nЭлементы массива (индексация):\n";
        for (int i = 0; i < n; i++) {
            std::cout << "arr[" << i << "] -> значение: " << arr[i] << '\n';
        }

        // Печатаем элементы массива с помощью указателя и инкрементации адреса
        std::cout << "\nЭлементы массива (инкрементация адреса):\n";
        for (int i = 0; i < n; i++) {
            std::cout << "ptr[" << i << "] -> адрес: " << (ptr + i)
                      << " значение: " << *(ptr + i) << std::endl;
        }
}

