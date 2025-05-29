#include <iostream>
#include <iomanip> // ������⥪� ��� std::setw, �� �� ��⠭����� �ਭ� ������
#include <cstdlib> // ��� srand() � rand()
#include <ctime> // ��� ����祭�� ⥪�饣� �६���

// �᭮���� �㭪�� Task_2a
void Task_2a() {
    const int size = 5;
    int matrixA[size][size];

    // ���������� ������: ������� �� ���������, �㫨 ? � ��⠫��� �����
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j)
                matrixA[i][j] = 1;
            else
                matrixA[i][j] = 0;
        }
    }

    // �뢮� ������
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrixA[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// �᭮���� �㭪�� Task_2b
void Task_2b() {
    const int SIZE = 8; // ���塞 ࠧ��� ������

        // ���樠������ ������� ��砩��� �ᥫ
        std::srand(std::time(nullptr));

        int matrixB[SIZE][SIZE];

        // ���������� ������ �ᥢ����砩�묨 �᫠�� �� -15 �� 15
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                matrixB[i][j] = std::rand() % 31 - 15; // ��������: -15..15
            }
        }

        // �뢮� ������ � ��ࠢ��������
            for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                std::cout << std::setw(5) << matrixB[i][j];
            }
            std::cout << '\n' << '\n';
        }

        // ���᫥��� �㬬� ����⮢ ��� ������� ���������
        int sumAboveMainDiagonal = 0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = i + 1; j < SIZE; ++j) { // j > i, �⮡� ���� ��� ���������
                sumAboveMainDiagonal += matrixB[i][j];
            }
        }

        // �뢮� १����
        std::cout << "�㬬� ����⮢, ������ ��� ������� ���������: "
                  << sumAboveMainDiagonal << std::endl;        
}
