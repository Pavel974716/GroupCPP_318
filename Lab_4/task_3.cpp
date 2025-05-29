#include <iostream>

// Основная функция Task_3
void Task_3() {

    // Используем цикл for для перебора символов от 'a' до 'z'
    for (char ch = 'a'; ch <= 'z'; ++ch) {

        // Выводим символ и его ASCII-код
        std::cout << ch << " - " << static_cast<int>(ch) << std::endl;
    }
}
