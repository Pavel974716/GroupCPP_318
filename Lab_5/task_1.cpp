#include <iostream>

// Объявление переменной в секции .bss (не инициализированная глобальная переменная)
int uninitialized_bss_var[3]; // по умолчанию нулевые значения, занимает секцию .bss

// Объявление переменной в секции .data (инициализированная глобальная переменная)
int initialized_data_var[3] = {1, 2, 3};

// Объявление функции с произвольной сигнатурой
void sampleFunction() {

}

// Главная функция Task_1
void Task_1(void *ptr) {

    // Переменная на стеке
    int stack_var = 10;

    // Массив на стеке
    int stack_array[3] = {4, 5, 6};

    // Вывод адреса функции main
    //std::cout << "Адрес функции main: " << (void*)main << '\n';
    std::cout << "Адрес функции main: " << ptr << '\n';

    // Вывод адреса произвольной функции
    std::cout << "\nАдрес функции sampleFunction: " << (void*)sampleFunction << '\n';

    // Адрес переменной на стеке
    std::cout << "\nАдрес переменной stack_var: " << (void*)&stack_var << '\n';

    // Адрес и элементы массива на стеке
    std::cout << "\nАдрес массива stack_array: " << (void*)stack_array << '\n';
    for(int i = 0; i < 3; ++i) {
        std::cout << "stack_array[" << i << "] (" << (void*)&stack_array[i] << ") = "
                       << stack_array[i] << '\n';
    }

    // Адрес переменной в секции .bss
    std::cout << "\nАдрес uninitialized_bss_var: " << (void*)uninitialized_bss_var << '\n';

    // Адрес переменной в секции .data
    std::cout << "Адрес initialized_data_var: " << (void*)initialized_data_var << '\n';
    std::cout << '\n';

    // Адрес и элементы массива в статической памяти (.bss)
    for(int i = 0; i < 3; ++i) {
        std::cout << "uninitialized_bss_var[" << i << "] ("
                       << (void*)&uninitialized_bss_var[i] << ") = " << uninitialized_bss_var[i] << '\n';
    }
    std::cout << '\n';
    for(int i = 0; i < 3; ++i) {
        std::cout << "initialized_data_var[" << i << "] ("
                       << (void*)&initialized_data_var[i] << ") = " << initialized_data_var[i] << '\n';
    }

    // Создание переменной в куче
    int *heap_var = new int(100);

    // Массив в куче
    int *heap_array = new int[3]{7,8,9};

    // Вывод адреса указателя на кучу и его значение
    std::cout << "\nАдрес указателя heap_var: " << &heap_var << '\n';
    std::cout << "\nЗначение heap_var (адрес объекта): " << (void*)heap_var << '\n';

    // Адрес и элементы массива на куче
    for(int i=0; i<3; ++i) {
        std::cout << "heap_array[" << i << "] (" << (void*)(heap_array + i) << ") = " << *(heap_array + i) << std::endl;
    }

    // Освобождаем  память
    delete heap_var;
    delete[] heap_array;
}
