#include <iostream>
#include <string>

const int MAX_LINES = 25;
const int MAX_LENGTH = 80;

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�
void in_int(const std::string & prompt, int & var); // �㭪�� ������᭮�� ����� 楫��� �᫠

// ����஢�� �� ��䠢���
void sortAlphabetically(std::string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ����஢�� �� �����
void sortByLength(std::string arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j].length() > arr[j + 1].length()) {
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ���� ����� ��ப� � �஢�મ� �����
bool inputOneLine(std::string & line, int lineNumber) {
    while (true) {
        line = in_string("��ப� " + std::to_string(lineNumber) + ": ");

        if (line.empty()) {
            return false; // �����襭�� �����
        }

        if (line.length() > MAX_LENGTH) {
            std::cout << "�訡��: ��ப� �ॢ�蠥� 80 ᨬ�����. ������ ����.\n\n";
            continue;
        }

        return true;
    }
}

// ���� ��� ��ப
int inputAllLines(std::string arr[]) {
    int count = 0;
    while (true) {
        std::cout << "������ ��ப� (���ᨬ� 25 ��ப, �� ����� 80 ᨬ����� ������, ����� ��ப� - �����襭��):\n\n";
        count = 0;
        for (int i = 0; i < MAX_LINES; ++i) {
            std::string line;
            if (!inputOneLine(line, i + 1)) {
                break;
            }
            arr[count++] = line;
        }

        if (count == 0) {
            std::cout << "��� ��ப ��� ���஢��. ������ ����.\n\n";
        } else {
            break;
        }
    }
    return count;
}

// ����祭�� �롮� ���짮��⥫�
int getSortChoice() {
    int choice;
    std::cout << "\n�롥�� ᯮᮡ ���஢��:\n";
    std::cout << "1 - �� ��䠢���\n";
    std::cout << "2 - �� ����� ��ப�\n\n";
    while (true) {
        in_int("��� �롮�: ", choice);

        if (choice == 1 || choice == 2) {
            return choice;
        } else {
            std::cout << "������ �롮�. ������ ����.\n\n";
        }
    }
}

// ������� �㭪�� Task_6
void Task_6() {
    std::string lines[MAX_LINES];

    int count = inputAllLines(lines);
    int choice = getSortChoice();

    if (choice == 1) {
        sortAlphabetically(lines, count);
    } else {
        sortByLength(lines, count);
    }

    std::cout << "\n�����஢���� ��ப�:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << lines[i] << std::endl;
    }
}
