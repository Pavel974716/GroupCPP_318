#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

// Разбор строки вида: "Страна, Город, Улица, Дом".
// При ошибке формата бросает std::invalid_argument .
void Parse(const std::string& line, Address* const address);

// Нормализация и проверки. При проблемах бросает std::runtime_error.
void Unify(Address* const address);

// Единый формат вывода
std::string Format(const Address& address);

#endif // ADDRESS_H
