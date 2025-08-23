#include <iostream>
#include <string>
#include <limits>

enum class ProgrEnum { Task_1, Task_2, Task_3, Task_4, Task_5 };

// ?? ���� 楫��� �᫠ � �஢�મ�
int in_int(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear(); // ���� �訡��
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

// ?? ���� ��ப�
std::string in_string(const std::string& message) {
    std::string input;
    std::cout << message;
    std::getline(std::cin, input);
    return input;
}

// ?? ������� �㭪��
int main() {
    std::cout << "��ࠢ����.\n";

    while (true) {
        int n = in_int("\n������ ����� ������� �� 1-5: ");
        ProgrEnum progrEnum = static_cast<ProgrEnum>(n - 1);

        if (progrEnum == ProgrEnum::Task_1) {
            std::cout << "�믮������ ������� 1\n";
        } else if (progrEnum == ProgrEnum::Task_2) {
            std::cout << "�믮������ ������� 2\n";
        } else if (progrEnum == ProgrEnum::Task_3) {
            std::cout << "�믮������ ������� 3\n";
        } else if (progrEnum == ProgrEnum::Task_4) {
            std::cout << "�믮������ ������� 4\n";
        } else if (progrEnum == ProgrEnum::Task_5) {
            std::cout << "�믮������ ������� 5\n";
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
