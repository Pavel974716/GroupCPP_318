#include <iostream>
#include <string>
#include <cctype>  // ��� isdigit, islower, toupper.

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�

// �஢�ઠ �ࠢ��쭮�� �ଠ� 㯠�������� ��ப�
bool isValidCompressed(const std::string & s) {
    size_t i = 0;
    const size_t len = s.length();

    while (i < len) {
        // �஢��塞, �� �� ���� ��� �� 1 �� 9
        if (i >= len || s[i] < '1' || s[i] > '9') {
            return false;
        }
        i++;

        // ��᫥ �᫠ ������ ��� ���筠� �㪢�
        if (i >= len || !islower(s[i])) {
            return false;
        }
        i++; // ���室 � ᫥���饩 ��㯯�
    }
    return true;
}

// ��ᯠ����� ��ப� � �८�ࠧ������� � ���孨� ॣ����
std::string decompress(const std::string & compressed) {
    std::string result;
    size_t i = 0;
    const size_t len = compressed.length();

    while (i < len) {

           // ��⠥� ���� ����
           const int count = compressed[i] - '0';
            i++;

            // ������騩 ᨬ��� ? �㪢�
            const char letter = std::toupper(compressed[i]);
            i++;
            result.append(count, letter);
       }
    return result;
}

// ������� �㭪�� Task_4
void Task_4() {
    std::string compressed;

    // �����塞 ���� �� �� ���, ���� �� ����稬 ���४��� ��ப�
    while (true) {
        compressed = in_string("������ 㯠�������� ��ப� (���ਬ��, 4a5c4d): ");


        if (isValidCompressed(compressed)) {
            break;
        } else {
            std::cout << "�訡��: ��ப� ����� ������ �ଠ�! ���஡�� ᭮��.\n\n";
        }
    }

    const std::string original = decompress(compressed);
    std::cout << "��ᯠ�������� ��ப�: " << original << std::endl;
}
