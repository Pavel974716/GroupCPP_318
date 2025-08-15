#include "address.h"
#include <iostream>
#include <string>

// Главная функция Task_8
void Task_8() {
    std::cout << "Введите адреса в формате:\n";
    std::cout << "Страна, Город, Улица Дом\n";
    std::cout << "Пример: Россия, Москва, пр-д Кочновского 15\n\n";

    std::string line;
    while (getline(std::cin, line)) {        
        Address address;
        try {
            Parse(line, & address);
            Unify(& address);
            std::cout << Format(address) << std::endl;            
            break;
        } catch (...) {
            std::cout << "exception\n";
            std::cout << "Введите адреса в формате:\n";
            std::cout << "Страна, Город, Улица Дом\n";
            std::cout << "Пример: Россия, Москва, пр-д Кочновского 15\n\n";
        }
    }
}
