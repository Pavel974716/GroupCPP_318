#include "address.h"
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <cctype>

// �����쭠� trim ��� �஢�ન "q"
static inline void trim_local(std::string& s) {
    size_t left = 0;
    while (left < s.size() && std::isspace(static_cast<unsigned char>(s[left]))) ++left;
    if (left == s.size()) { s.clear(); return; }
    size_t right = s.size() - 1;
    while (right > left && std::isspace(static_cast<unsigned char>(s[right]))) --right;
    s = s.substr(left, right - left + 1);
}

// ������� �㭪�� Task_2
void Task_2() {
    std::ios::sync_with_stdio(false);
    std::string line;

    while (true) {
        std::cout << "������ ���� � �ଠ�: ��࠭�, ��த, ����, ��� ��� ������ q ��� ��室�.\n> ";

        if (!std::getline(std::cin, line)) {
            std::cout << "�����襭�� ࠡ���.\n";
            break;
        }

        // ��室 �� 'q' ��� 'Q' (� ���⮬ ��������� �஡����)
        std::string quit = line;
        trim_local(quit);
        if (quit == "q" || quit == "Q") {
            std::cout << "�����襭�� ࠡ���.\n";
            break;
        }

        // �������᪠� ������ ��� ��祪
        std::unique_ptr<Address> address(new Address());

        try {
            Parse(line, address.get());
            Unify(address.get());
            std::cout << "��ଠ��������� ����: " << Format(*address) << '\n';
        }
        catch (const std::invalid_argument& e) {
            std::cout << "�訡��: " << e.what() << '\n';
        }
        catch (const std::runtime_error& e) {
            std::cout << "�訡��: " << e.what() << '\n';
        }
        catch (const std::exception& e) {
            std::cout << "���।�������� �訡��: " << e.what() << '\n';
        }
    }
}

