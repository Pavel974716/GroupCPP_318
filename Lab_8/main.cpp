/* ������ୠ� ࠡ�� �8
 * ��㯯� �318
 * Developer: ��㤥�殢 �.�.
 * OS: Windows 10 ��௮�⨢���
 * Locale (����஢��): IBM866
 */

#include <iostream>
#include <string>
#include <limits>

void Task_1(); // ������� �1
void Task_2(); // ������� �2
void Task_3(); // ������� �3
void Task_4(); // ������� �4
void Task_5(); // ������� �5

enum class ProgrEnum { Task_1, Task_2, Task_3, Task_4, Task_5 };

// ���� 楫��� �᫠ � �஢�મ�
int in_int(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // ��� �訡��
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���⪠ �����
            std::cout << "�訡��! ������ 楫�� �᫮.\n";
        } else if (value < 1 || value > 5) {
            std::cout << "��᫮ ������ ���� �� 1 �� 5.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

// ���� ��ப�
std::string in_string(const std::string& message) {
    std::string input;
    std::cout << message;
    std::getline(std::cin, input);
    return input;
}

// ������� �㭪��
int main() {
    std::cout << "��ࠢ����.\n";

    while (true) {
        int n = in_int("\n������ ����� ������� �� 1-5: ");
        ProgrEnum progrEnum = static_cast<ProgrEnum>(n - 1);

        if (progrEnum == ProgrEnum::Task_1) {
            std::cout << "������� �1\n\n";
            Task_1();
        } else if (progrEnum == ProgrEnum::Task_2) {
            std::cout << "������� �2\n\n";
            Task_2();
        } else if (progrEnum == ProgrEnum::Task_3) {
            std::cout << "������� �3\n\n";
            Task_3();
        } else if (progrEnum == ProgrEnum::Task_4) {
            std::cout << "������� �4\n\n";
            Task_4();
        } else if (progrEnum == ProgrEnum::Task_5) {
            std::cout << "������� �5\n\n";
            Task_5();
        }

        while (true) {
            std::string bukv = in_string("\n���� �� �� ��� �� �ணࠬ��? (y/n): ");

            if (bukv == "y" || bukv == "Y") {
                std::cout << "\n���ᨡ� �� �஢���! �� ᢨ�����!\n";
                return 0;
            } else if (bukv == "n" || bukv == "N") {
                break; // �த������ �믮������
            } else {
                std::cout << "�⢥� �� �ᯮ����. ��������, ������ 'y' ��� 'n'.\n";
            }
        }
    }

    return 0;
}

