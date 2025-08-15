#include "address.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>

void Parse(const std::string & line, Address *const address) {

    // Пример: "Россия, Москва, пр-д Кочновского15"
    std::istringstream iss(line);
    std::getline(iss, address->Country, ',');
    std::getline(iss, address->City, ',');
    std::getline(iss, address->Street, ',');

    if (address->Country.empty() || address->City.empty() || address->Street.empty()) {
        throw std::runtime_error("Ошибка при разборе строки");
    }

    // Попробуем разбить улицу и дом по последнему пробелу
    size_t pos = address->Street.find_last_of(" ");
    if (pos == std::string::npos) {
        throw std::runtime_error("Некорректный формат строки улицы");
    }

    address->House = address->Street.substr(pos + 1);
    address->Street = address->Street.substr(0, pos);
}

void Unify(Address *const address) {

    // Пример простой замены "пр-д" на "проезд"
    std::string & street = address->Street;
    if (street.find("пр-д") != std::string::npos) {
        street.replace(street.find("пр-д"), 4, "проезд");
    }

    // Удалим лишние пробелы в начале и конце всех строк
    auto trim = [](std::string & s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    };

    trim(address->Country);
    trim(address->City);
    trim(address->Street);
    trim(address->House);

    if (address->House.empty()) {
        throw std::runtime_error("Не указан номер дома");
    }
}

std::string Format(const Address & address) {
    return address.Country + ", " + address.City + ", " + address.Street + " " + address.House;
}
