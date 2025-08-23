#include <iostream>
#include <string>

// Класс для перебора паролей методом brute-force
class Bruteforce {
private:
    static std::string allowedChars; // Статическая переменная для допустимых символов
    size_t minLength;                 // Минимальная длина пароля
    size_t maxLength;                 // Максимальная длина пароля
    std::string targetPassword;       // Пароль для поиска

public:
    // Конструктор
    Bruteforce(size_t minLen, size_t maxLen)
        : minLength(minLen), maxLength(maxLen) {}

    void setTargetPassword(const std::string& password) {
        targetPassword = password;
    }

    bool bruteForce() {
        for (size_t length = minLength; length <= maxLength; ++length) {
            std::string currentPassword;
            if (generateCombinations(currentPassword, length))
                return true; // Пароль найден
        }
        return false; // Не найден
    }

    static void setAllowedChars(const std::string& chars) {
        allowedChars = chars;
    }

private:
    bool generateCombinations(std::string& current, size_t length) {
        if (current.size() == length) {
            if (current == targetPassword) {
                std::cout << "Пароль найден: " << current << std::endl;
                return true;
            }
            return false;
        }

        for (char ch : allowedChars) {
            current.push_back(ch);
            if (generateCombinations(current, length))
                return true;
            current.pop_back();
        }
        return false;
    }
};

// Инициализация статической переменной
std::string Bruteforce::allowedChars = "";

// Функция для проверки
bool isAllowedChar(char ch) {
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

// Функция для проверки валидности пароля по длине и символам
bool isPasswordValid(const std::string& password, size_t minLen, size_t maxLen) {
    if (password.length() < minLen || password.length() > maxLen)
        return false;

    for (char ch : password) {
        if (!isAllowedChar(ch))
            return false;
    }
    return true;
}

// Главная функция Task_1
void Task_1() {

    // Устанавливаем допустимые символы для brute-force
    Bruteforce::setAllowedChars("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    size_t minLen = 2;
    size_t maxLen = 3;

    Bruteforce bf(minLen, maxLen);

    std::string passwordToFind;

    // Ввод пароля с проверкой валидности
    do {
        std::cout << "\nВведите пароль для поиска (от " << minLen << " до " << maxLen << " символов, только буквы и цифры): ";
        std::getline(std::cin, passwordToFind);

        if (!isPasswordValid(passwordToFind, minLen, maxLen)) {
            std::cout << "Пароль не соответствует требованиям. Попробуйте снова.\n";
        } else {
            break; // Валидный пароль введён
        }
    } while (true);

    bf.setTargetPassword(passwordToFind);

    if (!bf.bruteForce()) {
        std::cout << "Пароль не найден в заданных ограничениях.\n";
    }
}
