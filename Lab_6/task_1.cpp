#include <iostream>
#include <string>

// ����� ��� ��ॡ�� ��஫�� ��⮤�� brute-force
class Bruteforce {
private:
    static std::string allowedChars; // ����᪠� ��६����� ��� �����⨬�� ᨬ�����
    size_t minLength;                 // �������쭠� ����� ��஫�
    size_t maxLength;                 // ���ᨬ��쭠� ����� ��஫�
    std::string targetPassword;       // ��஫� ��� ���᪠

public:
    // ���������
    Bruteforce(size_t minLen, size_t maxLen)
        : minLength(minLen), maxLength(maxLen) {}

    void setTargetPassword(const std::string& password) {
        targetPassword = password;
    }

    bool bruteForce() {
        for (size_t length = minLength; length <= maxLength; ++length) {
            std::string currentPassword;
            if (generateCombinations(currentPassword, length))
                return true; // ��஫� ������
        }
        return false; // �� ������
    }

    static void setAllowedChars(const std::string& chars) {
        allowedChars = chars;
    }

private:
    bool generateCombinations(std::string& current, size_t length) {
        if (current.size() == length) {
            if (current == targetPassword) {
                std::cout << "��஫� ������: " << current << std::endl;
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

// ���樠������ ����᪮� ��६�����
std::string Bruteforce::allowedChars = "";

// �㭪�� ��� �஢�ન
bool isAllowedChar(char ch) {
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

// �㭪�� ��� �஢�ન ��������� ��஫� �� ����� � ᨬ�����
bool isPasswordValid(const std::string& password, size_t minLen, size_t maxLen) {
    if (password.length() < minLen || password.length() > maxLen)
        return false;

    for (char ch : password) {
        if (!isAllowedChar(ch))
            return false;
    }
    return true;
}

// ������� �㭪�� Task_1
void Task_1() {

    // ��⠭�������� �����⨬� ᨬ���� ��� brute-force
    Bruteforce::setAllowedChars("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    size_t minLen = 2;
    size_t maxLen = 3;

    Bruteforce bf(minLen, maxLen);

    std::string passwordToFind;

    // ���� ��஫� � �஢�મ� ���������
    do {
        std::cout << "\n������ ��஫� ��� ���᪠ (�� " << minLen << " �� " << maxLen << " ᨬ�����, ⮫쪮 �㪢� � ����): ";
        std::getline(std::cin, passwordToFind);

        if (!isPasswordValid(passwordToFind, minLen, maxLen)) {
            std::cout << "��஫� �� ᮮ⢥����� �ॡ������. ���஡�� ᭮��.\n";
        } else {
            break; // ������� ��஫� �����
        }
    } while (true);

    bf.setTargetPassword(passwordToFind);

    if (!bf.bruteForce()) {
        std::cout << "��஫� �� ������ � �������� ��࠭�祭���.\n";
    }
}
