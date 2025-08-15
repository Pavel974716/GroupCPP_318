#include <iostream>
#include <string>
#include <cctype>  // ��� �㭪権 isalpha, isdigit, toupper.

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�

// �஢�ઠ �ࠢ��쭮�� �ଠ� 㯠�������� ��ப�:
// ��ଠ�: �᫮ �� 1 �� 9 + ���� ��� ����� �㪢 �����, ���������
bool isValidCompressed(const std::string & s) {
    size_t i = 0;            // ������ ��� ��室� �� ��ப�
    const size_t len = s.length();

    while (i < len) {

        // �஢��塞, �� ⥪�騩 ᨬ��� ��� �� '1' �� '9'
        if (i >= len || !isdigit(s[i]) || s[i] == '0') {
            return false;   // ��ଠ� ������, ⠪ ��� �᫮ ��������� ��� ࠢ�� 0
        }
        ++i; // ���室�� � �㪢�� ��᫥ �᫠

        // ������ ��� ��� ������ ���� �㪢� (��, ���孨� ��� ������ ॣ����)
        if (i >= len || !isalpha(s[i])) {
            return false;   // ��ଠ� ������: ��᫥ �᫠ ��� �㪢
        }

        // ���뢠�� ����� ���騥 �㪢� (���� ��� �����)
        while (i < len && isalpha(s[i])) {
            ++i;
        }
        // ��᫥ �㪢  ���� ����� ��ப�, ���� ᫥����� ��㯯� ��稭����� � �᫠
    }
    return true; // �� ��㯯� ���४��
}

// ��ᯠ����� ��ப� � �८�ࠧ������� �㪢 � ���孨� ॣ����
// ������: ��� ������ ��㯯� �᫮ count + ����� ���騥 �㪢�,
// ������ �㪢� �����塞 count ࠧ
std::string decompress(const std::string & compressed) {
    std::string result;
    size_t i = 0;
    const size_t len = compressed.length();

    while (i < len) {

        // ��⠥� �᫮ (���� ��� �� '1' �� '9')
        int count = compressed[i] - '0';
        ++i;

        // ���뢠�� ����� ���騥 �㪢�, ������� ������ count ࠧ
        while (i < len && isalpha(compressed[i])) {

            // ������塞 � १���� count ࠧ �㪢� � ���孥� ॣ����
            result.append(count, std::toupper(compressed[i]));
            ++i;
        }
    }
    return result;
}

// ������� �㭪�� Task_4
void Task_4() {
    std::string compressed;

    while (true) {
        compressed = in_string("������ 㯠�������� ��ப� (���ਬ��, 4A5C4D): ");

        if (isValidCompressed(compressed)) {
            break;
        } else {
            std::cout << "�訡��: ��ப� ����� ������ �ଠ�! ���஡�� ᭮��.\n\n";
        }
    }

    // ��ᯠ���뢠�� � �뢮��� १����
    std::string original = decompress(compressed);
    std::cout << "��ᯠ�������� ��ப�: " << original << std::endl;

}
