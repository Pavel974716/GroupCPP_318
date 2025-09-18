#include "address.h"
#include <stdexcept>
#include <cctype>
#include <string>

// Trim: убрать пробелы по краям
static inline void trim(std::string& s) {
    size_t left = 0;
    while (left < s.size() && std::isspace(static_cast<unsigned char>(s[left]))) ++left;
    if (left == s.size()) { s.clear(); return; }
    size_t right = s.size() - 1;
    while (right > left && std::isspace(static_cast<unsigned char>(s[right]))) --right;
    s = s.substr(left, right - left + 1);
}

// Свернуть последовательности пробелов внутри строки в один пробел
static inline void squeeze_spaces(std::string& s) {
    std::string out; out.reserve(s.size());
    bool prev_space = false;
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(s[i]);
        bool is_space = (ch==' '||ch=='\t'||ch=='\n'||ch=='\r'||ch=='\f'||ch=='\v');
        if (is_space) {
            if (!prev_space && !out.empty()) out.push_back(' ');
            prev_space = true;
        } else {
            out.push_back(static_cast<char>(ch));
            prev_space = false;
        }
    }
    if (!out.empty() && out.back()==' ') out.pop_back();
    s.swap(out);
}

// Заменить все вхождения from -> to
static inline void replace_all(std::string& s, const std::string& from, const std::string& to) {
    if (from.empty()) return;
    size_t pos = 0;
    while ((pos = s.find(from, pos)) != std::string::npos) {
        s.replace(pos, from.size(), to);
        pos += to.size();
    }
}

// Нормализация названия улицы и простые подстановки сокращений
static inline void normalize_street(std::string& s) {
    trim(s);
    squeeze_spaces(s);

    // Без учёта регистра
    replace_all(s, "ул.", "улица");
    replace_all(s, "ул",  "улица");

    replace_all(s, "пр-д", "проезд");
    replace_all(s, "прд",  "проезд");

    replace_all(s, "пер.", "переулок");
    replace_all(s, "пер",  "переулок");

    replace_all(s, "просп.", "проспект");
    replace_all(s, "просп",  "проспект");
    replace_all(s, "пр-кт",  "проспект");

    replace_all(s, "б-р",  "бульвар");
    replace_all(s, "бул.", "бульвар");
    replace_all(s, "бул",  "бульвар");

    replace_all(s, "ш.",  "шоссе");
    replace_all(s, "ш",   "шоссе");

    replace_all(s, "наб.", "набережная");
    replace_all(s, "наб",  "набережная");

    squeeze_spaces(s);
}

static inline void normalize_component(std::string& s) {
    trim(s);
    squeeze_spaces(s);
}

void Parse(const std::string& line, Address* const address) {
    if (!address) throw std::invalid_argument("Внутренняя ошибка: указатель адреса равен null");

    // Проверка на пустую/пробельную строку
    bool only_ws = true;
    for (char c : line) {
        if (!std::isspace(static_cast<unsigned char>(c))) { only_ws = false; break; }
    }
    if (only_ws) throw std::invalid_argument("Ошибка формата: пустая строка");

    // Ждём ровно три запятых
    size_t p1 = line.find(',');                      if (p1 == std::string::npos) throw std::invalid_argument("Ошибка формата: нужно 4 поля через запятую");
    size_t p2 = line.find(',', p1 + 1);              if (p2 == std::string::npos) throw std::invalid_argument("Ошибка формата: нужно 4 поля через запятую");
    size_t p3 = line.find(',', p2 + 1);              if (p3 == std::string::npos) throw std::invalid_argument("Ошибка формата: нужно 4 поля через запятую");
    if (line.find(',', p3 + 1) != std::string::npos) throw std::invalid_argument("Ошибка формата: лишние запятые (слишком много полей)");

    // Распаковываем 4 поля
    address->Country = line.substr(0, p1);
    address->City    = line.substr(p1 + 1, p2 - p1 - 1);
    address->Street  = line.substr(p2 + 1, p3 - p2 - 1);
    address->House   = line.substr(p3 + 1);

    // Подрезаем пробелы
    trim(address->Country);
    trim(address->City);
    trim(address->Street);
    trim(address->House);

    // Пустые поля и ошибка формата
    if (address->Country.empty() || address->City.empty() ||
        address->Street.empty()  || address->House.empty()) {
        throw std::invalid_argument("Ошибка формата: одно или несколько полей пусты");
    }
}

void Unify(Address* const address) {
    if (!address) throw std::runtime_error("Внутренняя ошибка: адрес == null");

    normalize_component(address->Country);
    normalize_component(address->City);
    normalize_component(address->House);
    normalize_component(address->Street);
    normalize_street(address->Street);

    // Смысловые проверки
    if (address->Country.empty())
        throw std::runtime_error("Некорректный ввод: не указана страна");
    if (address->City.empty())
        throw std::runtime_error("Некорректный ввод: не указан город");
    if (address->Street.empty())
        throw std::runtime_error("Некорректный ввод: не указана улица");
    if (address->House.empty())
        throw std::runtime_error("Некорректный ввод: не указан дом");

    // Номер дома должен содержать хотя бы одну цифру
    bool has_digit = false;
    for (char ch : address->House) {
        if (std::isdigit(static_cast<unsigned char>(ch))) { has_digit = true; break; }
    }
    if (!has_digit)
        throw std::runtime_error("Некорректный ввод: номер дома должен содержать цифру");
}

std::string Format(const Address& address) {
    return address.Country + ", " + address.City + ", " +
           address.Street  + ", " + address.House;
}
