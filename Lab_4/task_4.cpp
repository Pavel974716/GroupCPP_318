#include <iostream>
#include <string>
#include <vector>

void in_int(const std::string & prompt, int & var); // �஢�ઠ ����� int

// ���⨢�� ��⮤
int factorialIterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result = result * i; // ������ �ଠ 㬭������ � ��ᢠ�������
    }
    return result;
}

// �����ᨢ�� ��⮤
long long factorialRecursive(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

// �᭮���� �㭪�� Task_4a
void Task_4a() {
    std::cout << "a)";
    int n;

    // ���� �᫠ � �஢�મ�
    while (true) {
            in_int("\n������ 楫�� �᫮ �� 0 �� 12 ��� ���᫥��� 䠪�ਠ��: ", n);
            if (n < 0 || n > 12) {
                std::cout << "�訡�� �����.\n";
            } else {
              break;
            }
      }

    // ���᫥��� ���⨢�� ��⮤��
    int factIterative = factorialIterative(n);
    std::cout << "\n����ਠ� " << n << " (���⨢��) ࠢ��: " << factIterative << '\n';

    // ���᫥��� ४��ᨢ�� ��⮤��
    long long factRecursive = factorialRecursive(n);
    std::cout << "����ਠ� " << n << " (४��ᨢ��) ࠢ��: " << factRecursive << std::endl;
}

// �᭮���� �㭪�� Task_4b
void Task_4b() {
    std::cout << "\nb)";
    int n;

    // ���� �᫠ � �஢�મ�
    while (true) {
            in_int("\n������ ����� �᫠ �������� (�� 0 �� 5000): ", n);
            if (n < 0 || n > 5000) {
                std::cout << "�訡�� �����.\n";
            } else {
              break;
            }
      }
        std::cout << '\n';
    if (n == 0) {
        std::cout << "��᫮ �������� �0 ࠢ�� 0" << '\n';
    } else if (n == 1) {
        std::cout << "��᫮ �������� �1 ࠢ�� 1" << '\n';
    } else {
        long long a = 0, b = 1, temp;
        for (int i = 2; i <= n; ++i) {
            temp = a + b;
            a = b;
            b = temp;
        }
        std::cout << "��᫮ �������� �" << n << " ࠢ�� " << b << std::endl;
    }
}

// �᭮���� �㭪�� Task_4�
void Task_4c() {
    std::cout << "\nc)";
    int n;

     // ���� �᫠ � �஢�મ�
     while (true) {
            in_int("\n������ 楫�� �᫮ ��� ��⠭���� (�� 1 �� 35): ", n);
            if (n < 1 || n > 35) {
                std::cout << "�訡�� �����.\n";
            } else {
              break;
            }
       }
     std::cout << '\n';

    // ����� ��� �࠭���� ��� ��ப ��ࠬ��� ��� ��।������ ���ᨬ��쭮� �����
    std::vector<std::string> lines;
    size_t max_length = 0;

    int row = 1;
    bool stop = false;
    while (!stop) {
        int sum = 0;
        std::string line_numbers;

        // ��ନ�㥬 ��ப� � �᫠��
        for (int i = row; i >= 1; --i) {
            line_numbers += std::to_string(i) + " ";
            if (i == n) {
                stop = true;
            }
            sum += i;
        }
        line_numbers += std::to_string(sum);

        lines.push_back(line_numbers);
        if (sum == n) {
            break;
        }
        ++row;
    }

    // ��室�� ���ᨬ����� ����� ��ப�
    for (const auto & line : lines) {
        if (line.length() > max_length) { // �ࠢ����� ⥯��� ����� size_t
            max_length = line.length();
        }
    }

    // �뢮��� ��ࠬ��� � 業��஢�����
    for (const auto & line : lines) {
        int padding = static_cast<int>((max_length - line.length()) / 2);
        for (int i = 0; i < padding; ++i)
        std::cout << " ";
        std::cout << line << std::endl;
    }
}

