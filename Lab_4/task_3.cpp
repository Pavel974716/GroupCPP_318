#include <iostream>

// �᭮���� �㭪�� Task_3
void Task_3() {

    // �ᯮ��㥬 横� for ��� ��ॡ�� ᨬ����� �� 'a' �� 'z'
    for (char ch = 'a'; ch <= 'z'; ++ch) {

        // �뢮��� ᨬ��� � ��� ASCII-���
        std::cout << ch << " - " << static_cast<int>(ch) << std::endl;
    }
}
