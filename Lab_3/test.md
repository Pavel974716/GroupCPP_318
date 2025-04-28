# **3.1 Что выводят программы, если есть ошибки исправьте их:**
## a) ***Неправильный код.***
```cpp
int return 5(){
return 5
}i
nt return8(){
return;
}i
nt main( {
std::cout << return5() + return8() << ;
return 0
}
```
## a) ***Исправленный код***
```cpp
include <iostream>

int return5() {
    return 5; 
}

int return8() {
    return 8; 
}

int main() {
    std::cout << return5() + return8(); 
    return 0; 
}
```
## ***Программа выведет сумму 13***
# ****************************************
## b) ***Неправильный код.***
```cpp
int return() {
return 5;
int return()
{
int k ;
k{3};
return k;
}
}i
nt main(){
std::cout << return() <<
std::cout << return() <<
}
```
## b) ***Исправленный код*** 
```cpp
#include <iostream>

int returnValue() {
    int k;
    k = 3; 
    return k;
}

int return() {
    return 5;
}

int main() {
    std::cout << return() << std::endl;       
    std::cout << returnValue() << std::endl;  
    return 0;
}
```
## ***Программа выведет 5 и 3***
# ****************************************
## c) ***Неправильный код.***
```cpp
void prints
()
{
std::cout << 'O_o' << ;
}i
nt main ()
{
std::cout << prints() <<
return 0;
}
```
## c) ***Исправленный код*** 
```cpp
#include <iostream>

void prints() {
    std::cout << "O_o";
}

int main() {
    prints(); 
    std::cout << std::endl; 
    return 0; 
}
```
## ***Программа выведет "O_o"***
# ****************************************
## d) ***Неправильный код.***
```cpp
int getNumbers()
{
return 6;
return;
}i
nt main()
{
std::cout << getNumbers(
std::cout << getNumbers)
std::cout << getNumbers
return 0;
}
```
## d) ***Исправленный код*** 
```cpp
#include <iostream>

int getNumbers() {
    return 6; 
}

int main() {
    std::cout << getNumbers() << '\n'; 
    std::cout << getNumbers() << '\n'; 
    std::cout << getNumbers() << '\n'; 
    return 0; 
}
```
## ***Программа выведет три раза 6 в каждой строчки***
# ****************************************
## e) ***Неправильный код.***
```cpp
int main()
{
std::cout << multiply(7, 8)
return 0;
}
void multiply(int a)
{
return a * b
}
int main() {
int x;
std::cin >> x;
constexpr y(x);
std::cout << y << std::endl;
return 0;
}
```
## e) ***Исправленный код*** 
```cpp
#include <iostream>

int multiply(int a, int b) {
    return a * b; 
}

int main() {
    std::cout << multiply(7, 8) << '\n'; 
    return 0;
}


int main2() {
    int x;
    std::cout << "Введите число: ";
    std::cin >> x;

    int y = x; 
    std::cout << y << std::endl; 
    return 0;
}
```
## ***Программа выведет 56***
# ****************************************
## f) ***Неправильный код.***
```cpp
#define VALUE
int main() {
#if (VALUE == 0)
std::cout << VALUE <<"\n";
#elif (VALUE == 1)
std::cout << VALUE <<"\n";
#
elif
std::cout << VALUE <<"\n";
}
```
## f) ***Исправленный код*** 
```cpp
#include <iostream>

#define VALUE 1

int main() {
#if (VALUE == 0)
    std::cout << VALUE << "\n";
#elif (VALUE == 1)
    std::cout << VALUE << "\n";
#else
    std::cout << VALUE << "\n";
#endif
    return 0;
}
```
## ***Программа выведет 1***
# ****************************************
## g) ***Неправильный код.***
```cpp
namespace Mix {
enum class Fruits {
LEMON,
APPLE
} enum class Colors {
RED,
BLACK
}
};
int main() {
Fruits fruit = Fruits::LEMON;
std::cout << "MIX\n";
return 1;
}
```
## g) ***Исправленный код*** 
```cpp
#include <iostream>

namespace Mix {
    enum class Fruits {
        LEMON,
        APPLE
    };

    enum class Colors {
        RED,
        BLACK
    };
}

int main() {
    Mix::Fruits fruit = Mix::Fruits::LEMON; 
    std::cout << "MIX\n"; 
    return 0; 
}
```
## ***Программа выведет "MIX"***
# ****************************************
## h) ***Неправильный код.***
```cpp
namespace DoMath
{
int subtract(int x, int y)
{
return x , y;
}
namespace DoMath
{
int add(int x, int y)
{
return x | y;
}
}} auto main()
{
std::cout << DoMath::add(5, 4) << '\n';
std::cout << ::subtract(5, 4) << '\n';
return 0;
}
```
## h) ***Исправленный код*** 
```cpp
#include <iostream>

namespace DoMath {
    int subtract(int x, int y) {
        return x - y;
    }

    int add(int x, int y) {
        return x + y;
    }
}

int main() {
    std::cout << DoMath::add(5, 4) << '\n';
    std::cout << DoMath::subtract(5, 4) << '\n';
    return 0;
}
```
## ***Программа выведет 9 и 1 на разных строчках***
# ****************************************
# **3.2 Чтобы программа cкомпилировалась нужно что-то добавить, нельзя удалять или комментировать программный код:**
## ***Неправильный код.***
```cpp
int tmp 1;
int main() {
tmp 3;
std::cout << "Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять
здесь пустые строки или
комментировать
<< std::endl;
return;
int getNumbers( {
int tmp = 1;
return;
}
```
## ***Исправленный код*** 
```cpp
#include <iostream>

int tmp = 1;

int main() {
    int tmp = 3;
    std::cout << "Глобальная переменная tmp: " << ::tmp << '\n';
    std::cout << "Локальная переменная tmp: " << tmp << '\n';
    std::cout << "zzz \":)\" ";
    std::cout << "Чтобы программа скомпилилась нужно что-то добавить а нельзя удалять \n"
                 "\n"
                 "здесь пустые строки или \n"
                 "\n"
                 "коментировать!"
                 << std::endl;
    return 0;
}

int getNumbers() {
    int tmp = 1;
    return tmp;
}
```






