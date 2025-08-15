#include <iostream>
#include <string>

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�

// ������� �㭪�� Task_5
void Task_5() {
    std::string input;
    input = in_string("������ ��ப� (����. 100 ᨬ�����): ");

    // ������� ������� ᨬ�����
    size_t inputLength = input.length();
    std::cout << "\n������� ᨬ�����: " << inputLength << '\n';

    // ��࠭�稬 ����� ��ப� �� 100 ᨬ�����
    if (inputLength > 100) {
        input = input.substr(0, 100);
        std::cout << "��ப� ��१��� �� 100 ᨬ�����." << '\n';
    }

    // �����塞 ⠡��樨 �� �஡���
    for (char & ch : input) {
        if (ch == '\t') {
            ch = ' ';
        }
    }

    // ����塞 �������騥�� �஡���
    std::string result;
    bool prev_space = false;

    for (char ch : input) {
        if (ch == ' ') {
            if (!prev_space) {
                result += ch;
                prev_space = true;
            }
        } else {
            result += ch;
            prev_space = false;
        }
    }

    // ����塞 ��砫�� � ������ �஡���
    size_t first = result.find_first_not_of(' ');
    size_t last = result.find_last_not_of(' ');
    if (first != std::string::npos) {
        result = result.substr(first, last - first + 1);
    } else {
        result = ""; // C�ப� �� ����� �஡����
    }

    std::cout << "�������: \"" << result << "\"" << std::endl;
}
