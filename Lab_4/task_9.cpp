#include <iostream>

//  �㭪�� ��� ������ ���⠬�
void swapEvenOdd(char *arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        char temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

// �᭮���� �㭪�� Task_9
void Task_9() {
    char arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    std::cout << "��室�� ����� ���ᨢ�:\n";
    for (int i = 0; i < 12; i++) {
        std::cout << "�祩�� " << i << ": " << static_cast<int>(arr[i]) << std::endl;
    }

    swapEvenOdd(arr, 12);

    std::cout << "\n����� ��᫥ ࠡ��� �㭪樨:\n";
    for (int i = 0; i < 12; i++) {
        std::cout << "�祩�� " << i << ": " << static_cast<int>(arr[i]) << std::endl;
    }
}
