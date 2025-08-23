#include <iostream>
#include <string>
#define CP866
#ifdef CP866
#define RU_BEG_UP_ALP 128 // А
#define RU_END_UP_ALP 159 // Я
#define RU_BEG_LW_ALP 160 // а
#define RU_END_LW_ALP 239 // я
#else
#endif
class PalindromeChecker {
public:
    static void run() {
        std::string input;

        while (true) {
            std::cout << "\nВведите строку (до 17 символов, q для выхода): ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Пустой ввод. Повторите попытку.\n";
                continue;
            }

            if (input == "q" || input == "Q") {
                std::cout << "Выход.\n";
                break;
            }

            if (input.length() > 17) {
                std::cout << "Превышен лимит символов. Повторите ввод (до 17 символов).\n";
                continue;
            }

            if (isPalindrome(input)) {
                std::cout << "Это палиндром.\n";
            } else {
                std::cout << "Это не палиндром.\n";
            }
        }
    }

private:
    static bool isAlphaOrDigit(unsigned char ch) {
        if (ch >= '0' && ch <= '9') return true;
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true;
        if ((ch >= RU_BEG_UP_ALP && ch <= RU_END_UP_ALP) || (ch >= RU_BEG_LW_ALP)) return true;
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
        return false;
    }

    static unsigned char toLowerRussian(unsigned char ch) {
        if (ch >= 'A' && ch <= 'Z') return ch + ('a' - 'A');
        if (ch >= RU_BEG_UP_ALP && ch <= RU_END_UP_ALP) return ch + (RU_BEG_LW_ALP - RU_BEG_UP_ALP); // A - Я
        return ch;
    }

    static bool isPalindrome(const std::string& str) {
        std::string cleaned;

        for (unsigned char ch : str) {
            if (isAlphaOrDigit(ch)) {
                cleaned += toLowerRussian(ch);
            }
        }

        int left = 0;
        int right = static_cast<int>(cleaned.length()) - 1;

        while (left < right) {
            if (cleaned[left] != cleaned[right])
                return false;
            ++left;
            --right;
        }

        return true;
    }
};

// Главная функция Task_2
void Task_2() {
    PalindromeChecker::run();
}



