#include <iostream>
#include <string>

// �㭪�� ��� ������ ���� ᨬ�����
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// �㭪�� ����⠭����
void permute(std::string & str, int l, int r) {
    if (l == r) {
        std::cout << str << std::endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]); // �ᯮ��㥬 �㭪�� swap
            permute(str, l + 1, r); // �����ᨢ�� ��뢠�� ��� ᫥���饣� �����
            swap(str[l], str[i]); // �����頥� ���⭮ ��� ᫥���饩 ���樨
        }
    }
}

// �᭮���� �㭪�� Task_7
void Task_7() {
    std::string phases = "UVW"; // ��ப� � 䠧���
    int n = phases.size();
    permute(phases, 0, n - 1); // ������� ����⠭����
}
