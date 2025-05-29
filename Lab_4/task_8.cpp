#include <iostream>
#include <functional>

void in_int(const std::string & prompt, int & var);

// ��।��塞 �����᪨� �㭪樨
int logical_and(int a, int b) {
    return a & b;
}

int logical_or(int a, int b) {
    return a | b;
}

int logical_xor(int a, int b) {
    return a ^ b;
}

// �㭪�� ��� �믮������ �����᪮� ����樨
int perform_operation(int a, int b, std::function<int(int, int)> operation) {
    return operation(a, b);
}

// �㭪�� ��� �믮������ �����᪮� ����樨 � 㪠��⥫�� �� �㭪��
int perform_operation_with_pointer(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// �᭮���� �㭪�� Task_8
void Task_8() {
    const int MIN_VALUE = 0; // �������쭮� ���祭�� ��� �����
    const int MAX_VALUE = 100; // ���ᨬ��쭮� ���祭�� ��� �����
    int choice;
    int num1, num2;

    std::cout << "�롥�� ������:\n";
    std::cout << "1 - �\n";
    std::cout << "2 - ���\n";
    std::cout << "3 - XOR\n";

    in_int("������ ����� ����樨 (1-3): ", choice); // ���� �롮� ����樨

    // �஢�ઠ ���४⭮�� �롮� ����樨
    while (choice < 1 || choice > 3) {
        std::cout << "�訡�� �����.\n";
        in_int("������ ����� ����樨 (1-3): ", choice);
    }

    in_int("������ ��ࢮ� 楫�� �᫮ � ��������� [0, 100]: ", num1); // ���� ��ࢮ�� �᫠
    while (num1 < MIN_VALUE || num1 > MAX_VALUE) {
        std::cout << "�訡�� �����.\n";
        in_int("������ ��ࢮ� 楫�� �᫮ � ��������� [0, 100]: ", num1);
    }

    in_int("������ ��஥ 楫�� �᫮ � ��������� [0, 100]: ", num2); // ���� ��ண� �᫠
    while (num2 < MIN_VALUE || num2 > MAX_VALUE) {
        std::cout << "�訡�� �����.\n";
        in_int("������ ��஥ 楫�� �᫮ � ��������� [0, 100]: ", num2);
    }

    switch (choice) {
        case 1: {
            // �ᯮ��㥬 std::function
            std::function<int(int, int)> operation = logical_and;
            std::cout << "�������: " << perform_operation(num1, num2, operation) << '\n';
            // �ᯮ��㥬 㪠��⥫� �� �㭪��
            std::cout << "������� (㪠��⥫�): " << perform_operation_with_pointer(num1, num2, logical_and) << std::endl;
            break;
        }
        case 2: {
            // �ᯮ��㥬 std::function
            std::function<int(int, int)> operation = logical_or;
            std::cout << "�������: " << perform_operation(num1, num2, operation) << '\n';
            // �ᯮ��㥬 㪠��⥫� �� �㭪��
            std::cout << "������� (㪠��⥫�): " << perform_operation_with_pointer(num1, num2, logical_or) << std::endl;
            break;
        }
        case 3: {
            // �ᯮ��㥬 std::function
            std::function<int(int, int)> operation = logical_xor;
            std::cout << "�������: " << perform_operation(num1, num2, operation) << '\n';
            // �ᯮ��㥬 㪠��⥫� �� �㭪��
            std::cout << "������� (㪠��⥫�): " << perform_operation_with_pointer(num1, num2, logical_xor) << std::endl;
            break;
        }
    }
}
