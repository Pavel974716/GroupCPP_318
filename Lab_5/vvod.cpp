#include <iostream>
#include <limits>
#include <string>

void in_int(const std::string & prompt, int & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "Ошибка ввода.\n" << '\n' << prompt;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void in_double(const std::string & prompt, double & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "Ошибка ввода.\n" << '\n' << prompt;        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void in_char(const std::string & prompt, char & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "Ошибка ввода.\n" << '\n' << prompt;        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Очищаем оставшиеся символы после успешного ввода
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string in_string(const std::string & prompt) {
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}
