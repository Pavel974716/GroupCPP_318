#include <iostream>
#include <cstring>  // ��� strncpy
#include <sstream>  // ��� istringstream
#include <cctype>   // ��� isdigit
#include <climits>  // ��� INT_MAX � INT_MIN

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�
void in_int(const std::string & prompt, int & var); // �㭪�� ������᭮�� ����� 楫��� �᫠

// �஢�ઠ, ���� �� ��ப� 楫� �᫮�, � ��⮬ ��९�������
bool isValidIntString(const std::string & str) {
    if (str.empty()) return false;

    size_t i = 0;
    bool isNegative = false;

    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    if (i == str.length()) return false;

    for (size_t j = i; j < str.length(); ++j) {
        if (!isdigit(str[j])) return false;
    }

    long long result = 0;
    i = 0;
    if (str[0] == '-' || str[0] == '+') {
        i = 1;
    }

    for (; i < str.length(); ++i) {
        result = result * 10 + (str[i] - '0');
        if (!isNegative && result > INT_MAX) return false;
        if (isNegative && -result < INT_MIN) return false;
    }

    return true;
}

// ������� �ᥫ � ��ப� � �롮� ��ࢮ�� ���������
bool extractFirstValidInt(const std::string & input, std::string & outNumber, int & count) {
    std::istringstream iss(input);
    std::string word;
    count = 0;
    outNumber.clear();

    while (iss >> word) {
        if (isValidIntString(word)) {
            count++;
            if (outNumber.empty()) {
                outNumber = word;
            }
        }
    }

    if (count > 0 && count <= 10) {
        return true;
    } else {
        return false;
    }
}

// �८�ࠧ������ �᫠ � ��ப�
void intToCString(int num, char *buffer) {
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    bool isNegative = false;
    int i = 0;

    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    while (num > 0) {
        buffer[i] = '0' + (num % 10);
        num = num / 10;
        i++;
    }

    if (isNegative) {
        buffer[i] = '-';
        i++;
    }

    buffer[i] = '\0';

    // ������
    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - 1 - j];
        buffer[i - 1 - j] = temp;
    }
}

// �८�ࠧ������ ��ப� � �᫮
int cStringToInt(const char *str) {
    int result = 0;
    int i = 0;
    bool isNegative = false;

    if (str[0] == '-') {
        isNegative = true;
        i = 1;
    }

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    if (isNegative) {
        return -result;
    } else {
        return result;
    }
}

// ������� �㭪�� Task_7
void Task_7() {
    const int SIZE = 100;
    char buffer[SIZE];

    int number;
    in_int("������ 楫�� �᫮ (�� ����� 10 �ᥫ): ", number);

    intToCString(number, buffer);
    std::cout << "������� (�᫮ � ��ப�): " << buffer << '\n';

    std::string input, extracted;
    int count = 0;
    bool valid;

    do {
        input = in_string("\n������ ��ப� � �� ����� 祬 10 楫묨 �᫠��: ");
        valid = extractFirstValidInt(input, extracted, count);
        if (!valid) {
            if (count == 0) {
                std::cout << "�訡��: � ��ப� �� ������� �� ������ �����⨬��� 楫��� �᫠.\n";
            } else {
                std::cout << "�訡��: � ��ப� ����� 10 �����⨬�� 楫�� �ᥫ.\n";
            }
        }
    } while (!valid);

    std::strncpy(buffer, extracted.c_str(), SIZE - 1);
    buffer[SIZE - 1] = '\0';

    int parsed = cStringToInt(buffer);
    std::cout << "������� (��ࢮ� �᫮ �� ��ப�): " << parsed << std::endl;
}
