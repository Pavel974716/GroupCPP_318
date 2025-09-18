#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

// ������ ��ப� ����: "��࠭�, ��த, ����, ���".
// �� �訡�� �ଠ� ��ᠥ� std::invalid_argument .
void Parse(const std::string& line, Address* const address);

// ��ଠ������ � �஢�ન. �� �஡����� ��ᠥ� std::runtime_error.
void Unify(Address* const address);

// ����� �ଠ� �뢮��
std::string Format(const Address& address);

#endif // ADDRESS_H
