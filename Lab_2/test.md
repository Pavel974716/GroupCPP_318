# **1. Найдите в программе ошибки, представите ниже рабочий вариант программы.**
## ***Неправильный код.***
```cpp
nt main() {
short a;
a(65599);
int 5 = 4;
int л = 4;
char ch;
ch{5};
float f;
f = 3,2;
}}
```
## ***Правильный код.***
```cpp
#include <iostream>
int main() {
short a;
a = 65599;
int s5 = 4;
int l = 4;
char ch {5};
float f;
f = 3,2;
}
```
# ****************************************
# **2. Какие значения выводит эта программа?**
## а) ***Почему z выводит неожиданные значения?***
```cpp
#include <iostream>
int main() {
int x = 5;
x = x - 2;
//a
std::cout << x << std::endl; // #a
int y = x;
//b
std::cout << y << std::endl; // #b
//c
std::cout << x + y << std::endl; // #c
//d
std::cout << x << std::endl; // #d
int z;
//e
std::cout << z << std::endl; // #e
}
```
## ***Ответ:*** 
### 3, 3, 6, 3, 90; 
### Потому что Z неинициализированная переменная


## b)
```cpp
#include <iostream>
int main() {
int x = 1;
x = x++;
std::cout << x << "\n";
}
```
## ***Ответ: 1***

## c)
```cpp
#include <iostream>
int main(){
int x = 1;
std::cout << ++x << "\n";
}
```
## ***Ответ: 2***
# ****************************************
# **3. Найдите в программе ошибки, можно только что-то добавлять убирать нельзя, и выведите результат.**
## a) ***Неправильный код***
```cpp 
#include <iostream>
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8{7};
int main( {
bitset<8> bits(0x4);
bits.set(option_1);
bits.flip(option_3);
bits.reset(option_7);
cin << "Bit 1 has value: " << bits.test(option_1) << '/n';
cin << Bit 3 has value: " << bits.test() << '\n';
cin << "Bit 7 has value: " << bits.test() < '\n';
cin<< "All the bits: " << bits << '\n;
}
```
## ***Правильный код***
```cpp
#include <iostream>
#include <bitset>
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8{7};
int main() {
std::bitset<8> bits(0x4);
bits.set(option_1);
bits.flip(option_3);
bits.reset(option_7);
std::cout << "cin" << "Bit 1 has value: " << bits.test(option_1) << '/n';
std::cout << "cin" << "Bit 3 has value: " << bits.test(option_2) << '\n';
std::cout << "cin" << "Bit 7 has value: " << bits.test(option_4) << '\n';
std::cout << "cin" << "All the bits: " << bits << '\n';
}
```
## b) ***Неправильный код***
```cpp
int main()
uint8_t a(1), b(1), c(3
a = a < 1;
printf("a: \n", a)
b <<= 1;
printf("b: %d \n", b);
c |= 1;
print("c: \n", c);
```
## ***Правильный код***
```cpp
#include <iostream>
int main(){
uint8_t a(1), b(1), c(3);
a = a < 1;
printf("a: \n", a);
b <<= 1;
printf("b: %d \n", b);
c |= 1;
printf("c: \n", c);
}
```
## c) ***Неправильный код***
```cpp
int main() {
int x (08);
std::cout << "x: " << x < endl;
int y = 0x5;
std::cout << "y: " < y << std::endl;
int bin(0);
bin = 0b101;
out << "bin 0b101: " << bin << std::endl
}
```
## ***Правильный код***
```cpp
#include <iostream>
int main() {
int x (0x08);
std::cout << "x: " << x <<std::endl;
int y = 0x5;
std::cout << "y: " << y << std::endl;
int bin(0);
bin = 0b101;
std::cout << "bin 0b101: " << bin << std::endl;
}
```
## d) ***Неправильный код***
```cpp
int main() {
int x{8};
std::cout << "hex: " << h << x << ndl;
std::cout << "oct: " << o<< x << std::endl;
out << "dec: " << dec << x << std::endl;
}
```
## ***Правильный код***
```cpp
#include <iostream>
int main() {
int x{8};
std::cout << "hex: " << std::hex << x << std::endl;
std::cout << "oct: " << std::oct << x << std::endl;
std::cout << "dec: " << std::dec << x << std::endl;
}
```
# ****************************************
# **4. Вычислите следующие выражения c использованием С++.**
## a) ***(true или false):***
```cpp
(true && true) || false = true
(false && true) || true = true
(false && true) || false || true = true 
(5 > 6 || 4 > 3) && (7 > 8) = false
!(7 > 6 || 3 > 4) = false
```
## b) Какой результат 0110 >> 2 в двоичной системе счисления?
## **Oтвет: 00010010**
## c) Какой результат 5 & 12 в десятичной системе счисления?
## **Oтвет: 4**
## d) Какой результат 5 ^ 12 в десятичной системе счисления?
## **Oтвет: 9**
# ****************************************
# **5. Конвертируйте двоичное число 0100 1101 в десятичную систему счисления.**
# (0 * 128) + (1 * 64) + (0 * 32) + (0 * 16) + (1 * 8) + (1 * 4) + (0 * 2) + (1 * 1) = **77**





