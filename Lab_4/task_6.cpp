#include <iostream>

void in_int(const std::string & prompt, int & var); // �஢�ઠ ����� int
void in_double(const std::string & prompt, double & var); // �஢�ઠ ����� double
void in_char(const std::string & prompt, char & var); // �஢�ઠ ����� char

// �᭮���� �㭪�� Task_6a
void Task_6a() {
    std::cout << "a)\n";
    int m;
    double fx;
    char cht;

    // ���� ������ � �஢�મ�
    in_int("������ 楫�� �᫮ m: ", m);
    in_double("������ �᫮ � ������饩 �窮� fx: ", fx);
    in_char("������ ᨬ��� cht: ", cht);

    // ���塞 㪠��⥫�
    int* p_m = &m;
    double* p_fx = &fx;
    char* p_cht = &cht;

    // �뢮� १���⮢
    std::cout << "\n�����⥫�: �த�������஢��� �ᯮ�짮����� �����஢ & � *:\n";
    std::cout << "-------------------------------------------------- ------\n";
    std::cout << "m = " << m << '\n';
    std::cout << "fx = " << fx << '\n';
    std::cout << "cht = " << cht << std::endl;

    // �ᯮ�짮����� & � *
    std::cout << "\n�ᯮ�짮����� & ������:\n";
    std::cout << "-----------------------\n";
    std::cout << "���� m = " << static_cast<void*>(p_m) << '\n';
    std::cout << "���� fx = " << static_cast<void*>(p_fx) << '\n';
    std::cout << "���� cht = " << static_cast<void*>(p_cht) << std::endl;

    std::cout << "\n�ᯮ���� ������� & � *:\n";
    std::cout << "-----------------------------\n";
    std::cout << "���祭�� �� ����� m = " << *p_m << '\n';
    std::cout << "���祭�� �� ����� fx = " << *p_fx << '\n';
    std::cout << "���祭�� �� ����� cht = " << *p_cht << std::endl;

    // �ᯮ�짮����� ⮫쪮 ��६����� 㪠��⥫�
    int* ptr_m = p_m;
    double* ptr_fx = p_fx;
    char* ptr_cht = p_cht;

    std::cout << "\n�ᯮ�짮������ ⮫쪮 ��६����� 㪠��⥫�:\n";
    std::cout << "----------------------------------\n";

    std :: cout <<  "���� m = "<< static_cast<void*>(ptr_m) << '\n';
    std :: cout <<  "���� fx = "<< static_cast<void*>(ptr_fx) << '\n';
    std :: cout <<  "���� cht= "<< static_cast<void*>(ptr_cht) << std::endl;

    // �ᯮ�짮����� ⮫쪮 ������ 㪠��⥫�
    std :: cout << "\n�ᯮ�짮����� ⮫쪮 ������ 㪠��⥫�:\n";
    std :: cout << "----------------------------------\n";

    std :: cout << "���祭�� �� ����� m= " << *ptr_m << '\n';
    std :: cout << "���祭�� �� ����� fx= " << *ptr_fx << '\n';
    std :: cout << "���祭�� �� ����� cht= " << *ptr_cht << std::endl;
}

// �᭮���� �㭪�� Task_6b
void Task_6b() {
    std::cout << "\nb)\n";
    int n;

        // ����訢��� � ���짮��⥫� ������⢮ ����⮢
        while (true) {
            in_int("������ ������⢮ ����⮢ (�� 1 �� 10): ", n);
            if (n < 1 || n > 10) {
                std::cout << "�訡�� �����.\n";
                std::cout << '\n';
            } else {
                break; // ���� ���४⥭, ��室�� �� 横��
            }
        }

        int arr[n]; // ���塞 ���ᨢ ࠧ��஬ n
        int* ptr = arr; // �����⥫� �� ���� ����� ���ᨢ�

        // ������塞 ���ᨢ ����⠬�
        std::cout << "\n������ " << n << " ����⮢:\n";
        for (int i = 0; i < n; i++) {
            in_int("������� " + std::to_string(i + 1) + ": ", arr[i]);
        }

        // ���⠥� ������ ���ᨢ� � ������� 㪠��⥫� � ������樨
        std::cout << "\n�������� ���ᨢ� (��������):\n";
        for (int i = 0; i < n; i++) {
            std::cout << "arr[" << i << "] -> ���祭��: " << arr[i] << '\n';
        }

        // ���⠥� ������ ���ᨢ� � ������� 㪠��⥫� � ���६���樨 ����
        std::cout << "\n�������� ���ᨢ� (���६����� ����):\n";
        for (int i = 0; i < n; i++) {
            std::cout << "ptr[" << i << "] -> ����: " << (ptr + i)
                      << " ���祭��: " << *(ptr + i) << std::endl;
        }
}

