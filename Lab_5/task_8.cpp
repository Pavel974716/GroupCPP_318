#include "address.h"
#include <iostream>
#include <string>

// ������� �㭪�� Task_8
void Task_8() {
    std::cout << "������ ���� � �ଠ�:\n";
    std::cout << "��࠭�, ��த, ���� ���\n";
    std::cout << "�ਬ��: �����, ��᪢�, ��-� ��筮�᪮�� 15\n\n";

    std::string line;
    while (getline(std::cin, line)) {        
        Address address;
        try {
            Parse(line, & address);
            Unify(& address);
            std::cout << Format(address) << std::endl;            
            break;
        } catch (...) {
            std::cout << "exception\n";
            std::cout << "������ ���� � �ଠ�:\n";
            std::cout << "��࠭�, ��த, ���� ���\n";
            std::cout << "�ਬ��: �����, ��᪢�, ��-� ��筮�᪮�� 15\n\n";
        }
    }
}
