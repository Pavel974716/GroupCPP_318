#include <iostream>
#include <string>

class PalindromeChecker {
public:
    static void run() {
        std::string input;

        while (true) {
            std::cout << "\n������ ��ப� (�� 17 ᨬ�����, q ��� ��室�): ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "���⮩ ����. ������ ������.\n";
                continue;
            }

            if (input == "q" || input == "Q") {
                std::cout << "��室.\n";
                break;
            }

            if (input.length() > 17) {
                std::cout << "�ॢ�襭 ����� ᨬ�����. ������ ���� (�� 17 ᨬ�����).\n";
                continue;
            }

            if (isPalindrome(input)) {
                std::cout << "�� ������஬.\n";
            } else {
                std::cout << "�� �� ������஬.\n";
            }
        }
    }

private:
    static bool isAlphaOrDigit(unsigned char ch) {
        if (ch >= '0' && ch <= '9') return true;
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true;
        if ((ch >= 192 && ch <= 223) || (ch >= 224)) return true;
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') return true;
        return false;
    }

    static unsigned char toLowerRussian(unsigned char ch) {
        if (ch >= 'A' && ch <= 'Z') return ch + ('a' - 'A');
        if (ch >= 192 && ch <= 223) return ch + 32;
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

int main() {
    PalindromeChecker::run();
    return 0;
}
