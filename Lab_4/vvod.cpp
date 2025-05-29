#include <iostream>
#include <limits>


void in_int(const std::string & prompt, int & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "�訡�� �����.\n" << '\n' << prompt;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void in_double(const std::string & prompt, double & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "�訡�� �����.\n" << '\n' << prompt;
        //std::cout << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void in_char(const std::string & prompt, char & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "�訡�� �����.\n" << '\n' << prompt;
        //std::cout << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // ��頥� ��⠢訥�� ᨬ���� ��᫥ �ᯥ譮�� �����
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
