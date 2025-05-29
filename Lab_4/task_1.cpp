#include <iostream>
#include <random> // ��� �⠭���⭮�� ������� ��砩��� �ᥫ
#include <ctime>  // ��� ����祭�� ⥪�饣� �६���

//  ��������� userRandom Task_1
int userRandom(int min, int max) {
    static unsigned int seed = static_cast<unsigned int>(time(0)); // ��⠭���� ��砫쭮�� ���祭��
    seed = (214013 * seed + 2531011); // ���⮩ ������� ��������� �������
    return (seed >> 16) % (max - min + 1) + min; // ������� �᫠ � ��������� [min, max]
}

// �㭪�� ��� ���᪠ �����㬠 � ���ᨬ㬠 � ���ᨢ�
void findMinMax(const int* arr, int size, int& minVal, int& maxVal) {
    minVal = arr[0];
    maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
}

// �᭮���� �㭪�� Task_1
void Task_1() {
    const int size = 10;
    int arrayStd[size];   // ���ᨢ ��� �⠭���⭮�� �������
    int arrayCustom[size]; // ���ᨢ ��� userRandom

    // ���樠������ �⠭���⭮�� �������
    std::mt19937 mt(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<int> dist(1, 100);

    // ���������� ���ᨢ��
    for (int i = 0; i < size; ++i) {
        arrayStd[i] = dist(mt);                  // �⠭����� �������
        arrayCustom[i] = userRandom(1, 100);   // ��� �������
    }

    // ��室�� � �뢮��� ������ � ���ᨬ� ��� ���ᨢ� �⠭������ �ᥫ
    int minStd, maxStd;
    findMinMax(arrayStd, size, minStd, maxStd);
    std::cout << "���ᨢ �⠭���⭮�� �������: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arrayStd[i] << " ";
    }
    std::cout << "\n������: " << minStd << "\n���ᨬ�: " << maxStd << std::endl;
    std::cout << '\n';

    // ��室�� � �뢮��� ������ � ���ᨬ� ��� ���ᨢ� userRandom
    int minCustom, maxCustom;
    findMinMax(arrayCustom, size, minCustom, maxCustom);
    std::cout << "���ᨢ �ਤ㬠����� �������: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arrayCustom[i] << " ";
    }
    std::cout << "\n������: " << minCustom << "\n���ᨬ�: " << maxCustom << std::endl;
}
