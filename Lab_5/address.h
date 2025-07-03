#ifndef ADDRESS_H
#define ADDRESS_H

#pragma once
#include <string>

struct Address {
    std::string Country;
    std::string City;
    std::string Street;
    std::string House;
};

void Parse(const std::string & line, Address *const address);
void Unify(Address *const address);
std::string Format(const Address & address);

#endif // ADDRESS_H
