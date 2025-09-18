#include "address.h"
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <cctype>

// Локальная trim для проверки "q"
static inline void trim_local(std::string& s) {
    size_t left = 0;
    while (left < s.size() && std::isspace(static_cast<unsigned char>(s[left]))) ++left;
    if (left == s.size()) { s.clear(); return; }
    size_t right = s.size() - 1;
    while (right > left && std::isspace(static_cast<unsigned char>(s[right]))) --right;
    s = s.substr(left, right - left + 1);
}

// Главная функция Task_2
void Task_2() {
    std::ios::sync_with_stdio(false);
    std::string line;

    while (true) {
        std::cout << "Введите адрес в формате: Страна, Город, Улица, Дом или нажмите q для выхода.\n> ";

        if (!std::getline(std::cin, line)) {
            std::cout << "Завершение работы.\n";
            break;
        }

        // Выход по 'q' или 'Q' (с учётом возможных пробелов)
        std::string quit = line;
        trim_local(quit);
        if (quit == "q" || quit == "Q") {
            std::cout << "Завершение работы.\n";
            break;
        }

        // Динамическая память без утечек
        std::unique_ptr<Address> address(new Address());

        try {
            Parse(line, address.get());
            Unify(address.get());
            std::cout << "Нормализованный адрес: " << Format(*address) << '\n';
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Ошибка: " << e.what() << '\n';
        }
        catch (const std::runtime_error& e) {
            std::cout << "Ошибка: " << e.what() << '\n';
        }
        catch (const std::exception& e) {
            std::cout << "Непредвиденная ошибка: " << e.what() << '\n';
        }
    }
}

