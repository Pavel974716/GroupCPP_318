#include <iostream>
#include <cstring>
#include <cctype>
#include <climits>

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�
void in_int(const std::string & prompt, int & var); // �㭪�� ������᭮�� ����� 楫��� �᫠

// �஢�ઠ, �� ��ப� ? �� ���४⭮� 楫�� �᫮ (��� ����, ��� ��९�������)
bool isValidIntegerString(const std::string &str) {
    if (str.empty()) return false; // ����� ��ப� ? �� �᫮

    size_t i = 0;
    bool isNegative = false;

    // ��ࠡ�⪠ �����
    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    if (i == str.length()) return false; // ⮫쪮 ���� ��� ���

    // �஢�ઠ, �� �� ��⠢訥�� ᨬ���� ? ����
    for (size_t j = i; j < str.length(); ++j) {
        if (!isdigit(static_cast<unsigned char>(str[j]))) return false;
    }

    // �஢�ઠ ��९������� �१ long long
    long long result = 0;
    i = (str[0] == '-' || str[0] == '+') ? 1 : 0;

    for (; i < str.length(); ++i) {
        result = result * 10 + (str[i] - '0');
        if (!isNegative && result > INT_MAX) return false;   // ��९������� ������⥫쭮��
        if (isNegative && -result < INT_MIN) return false;   // ��९������� ����⥫쭮��
    }

    return true;
}

// �஢�ઠ, �� ᨬ��� ? ���
bool isCharDigit(char c) {
    return c >= '0' && c <= '9';
}

// �८�ࠧ������ C-��ப� � int � �஢�મ� ��९�������
bool stringToInt(const char *str, int &out) {
    if (!str || *str == '\0') return false; // null ��� ����� ��ப�

    long long result = 0;
    int i = 0;
    bool isNegative = false;

    // ��ࠡ�⪠ �����
    if (str[i] == '-') {
        isNegative = true;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    if (str[i] == '\0') return false; // ⮫쪮 ���� ? �訡��

    // ���뢠�� ����
    while (str[i] != '\0') {
        if (!isCharDigit(str[i])) return false; // �� ��� ? �訡��

        result = result * 10 + (str[i] - '0');
        if (!isNegative && result > INT_MAX) return false; // ��९�������
        if (isNegative && -result < INT_MIN) return false; // ��९�������

        i++;
    }

    out = isNegative ? -static_cast<int>(result) : static_cast<int>(result);
    return true;
}

// �८�ࠧ������ int � C-��ப�
void intToCString(int num, char *buffer) {
    if (!buffer) return;

    if (num == 0) { // �⤥��� ��砩 ��� ���
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    bool isNegative = false;
    unsigned int unum;
    int i = 0;

    // �८�ࠧ㥬 � unsigned ��� ���४⭮� ��ࠡ�⪨ INT_MIN
    if (num < 0) {
        isNegative = true;
        unum = static_cast<unsigned int>(-(long long)num);
    } else {
        unum = static_cast<unsigned int>(num);
    }

    // �����뢠�� ���� � ���⭮� ���浪�
    while (unum > 0) {
        buffer[i++] = '0' + (unum % 10);
        unum /= 10;
    }

    // �᫨ �뫮 ����⥫쭮� ? ������塞 '-'
    if (isNegative) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0';

    // ������ ��ப�
    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }
}

// ���� ��ࢮ�� ���४⭮�� �᫠ � ��ப� (��䨪�� ��⮤)
bool findFirstInteger(const std::string &input, std::string &outNumber, int &count) {
    count = 0;
    size_t i = 0;

    while (i < input.length()) {

        // �ய�᪠�� ���, �� �� ��� � �� ����
        if (input[i] != '+' && input[i] != '-' && !isCharDigit(input[i])) {
            i++;
            continue;
        }

        size_t start = i;

        // �᫨ ���� ����, �஢��塞, �� �� ��� ���� ���
        if (input[i] == '+' || input[i] == '-') {
            i++;
            if (i >= input.length() || !isCharDigit(input[i])) {
                continue; // �� �᫮ ? ��� �����
            }
        }

        // ���뢠�� ����
        while (i < input.length() && isCharDigit(input[i])) {
            i++;
        }

        // ����稫� �����ப�, ����� ����� ���� �᫮�
        std::string numberStr = input.substr(start, i - start);

        // �஢�ઠ �᫠ �� ���४⭮���
        if (isValidIntegerString(numberStr)) {
            outNumber = numberStr;
            count = 1; // ��諨 ���� �᫮
            return true; // �ࠧ� ��室��
        }
    }
    return false; // �� ��諨 �� ������ ���४⭮�� �᫠
}

// ������� �㭪�� Task_7
void Task_7() {
    const int SIZE = 100;
    char buffer[SIZE];

    // ���� �᫠ � �८�ࠧ������ � ��ப�
    int number;
    in_int("������ 楫�� ������⥫쭮� �᫮ (�� ����� 10 ᨬ�����): ", number);

    intToCString(number, buffer);
    std::cout << "������� (�᫮ � ��ப�): " << buffer << '\n';

    // ���� ��ப� � ���� ��ࢮ�� �᫠
    std::string input, extracted;
    int count = 0;
    bool valid;

    do {
        input = in_string("\n������ ��ப� � �᫠�� (������ �᫮ �� ����� 10 ᨬ�����): ");
        valid = findFirstInteger(input, extracted, count);
        if (!valid) {
            std::cout << "�訡��: � ��ப� �� ������� �����⨬��� 楫��� �᫠.\n";
        }
    } while (!valid);

    // ��������� ���������� �᫠ � int
    std::strncpy(buffer, extracted.c_str(), SIZE - 1);
    buffer[SIZE - 1] = '\0';

    int parsed;
    if (stringToInt(buffer, parsed)) {
        std::cout << "������� (��ࢮ� �᫮ �� ��ப�): " << parsed << std::endl;
    } else {
        std::cout << "�訡�� �८�ࠧ������ �᫠ �� ��ப�.\n";
    }
}
