# **3 Найдите ошибки в программах и исправьте их, напишите результат вывода программ:**
## a) ***Неправильный код.***
```cpp
void main( {
short array[]{1,3,5,7,9};
short *ptr = array;
ptr = 111;
for (int i = 0; i < sizeof(array); ++i)
std::cout << " Значение элемента " << i << ": " << array +i << '\n';
}
```
## a) ***Исправленный код***
```cpp
#include <iostream>
int main() { 
    short array[] = {1, 3, 5, 7, 9}; 
    short *ptr = array; 
    for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); ++i) { 
        std::cout << "Значение элемента " << i << ": " << *(ptr + i) << '\n'; 
    }
    return 0; 
}
```
## Программа выведет:
### Значение элемента 0: 1
### Значение элемента 1: 3
### Значение элемента 2: 5
### Значение элемента 3: 7
### Значение элемента 4: 9
# ****************************************
## b) ***Неправильный код.***
```cpp
int main() {
int array[size]{1,3,5,7,9};
Func(&array, size);
}
void Func(int *ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << " Значение элемента " ББ<< ptr[i] << '\n';
std::cout << " Адрес элемента " << ptr[i << '\n';
}
```
## b) ***Исправленный код*** 
```cpp
#include <iostream>
void Func(int *ptr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Значение элемента: " << ptr[i] << '\n';
        std::cout << "Адрес элемента: " << &ptr[i] << '\n'; 
    }
}
int main() {
    const int size = 5; 
    int array[size] = {1, 3, 5, 7, 9}; 
    Func(array, size); 
    return 0; 
}
```
## Программа выведет:
### Значение элемента: 1
### Адрес элемента: 0x61fe88
### Значение элемента: 3
### Адрес элемента: 0x61fe8c
### Значение элемента: 5
### Адрес элемента: 0x61fe90
### Значение элемента: 7
### Адрес элемента: 0x61fe94
### Значение элемента: 9
### Адрес элемента: 0x61fe98
# ****************************************
## c) ***Неправильный код.***
```cpp
#include <iostream>
int main() {
short value;
short *p;
p = value;
*p = value;
*p = &value;
*p = *&value;
}
```
## c) ***Исправленный код*** 
```cpp
#include <iostream>
int main() {
    short value = 0; 
    short *p;
    p = &value; 
    *p = value; 
    std::cout << "Value: " << value << std::endl;  
    return 0; 
}
```
## Программа выведет:
### Value: 0
# ****************************************
## d) ***Неправильный код.***
```cpp
#include <iostream>
int main() {
char cvalue;
int ivalue;
short * ps;
char *pc;
void *pv {(int*)(cvalue)};
void *pv_1 {(char*)(&ivalue)};
std::cout << "pv->int" << *static_cast<int>(pv) << std::endl;
int *pi = {(int)(pv)};
std::cout << "pi=" << pv_1 << std::endl;
}
```
## d) ***Исправленный код*** 
```cpp
#include <iostream>
int main() {
    char cvalue = 'A'; 
    int ivalue = 42; 
    void *pv = static_cast<void*>(&cvalue); 
    void *pv_1 = static_cast<void*>(&ivalue);    
    std::cout << "cvalue: " << *static_cast<char*>(pv) << std::endl;    
    std::cout << "ivalue: " << *static_cast<int*>(pv_1) << std::endl;

    return 0;
}
```
## Программа выведет:
### cvalue: A
### ivalue: 42
# ****************************************
## e) ***Неправильный код.***
```cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref;
const short &ref1 = value;
const short &ref2 = 78;
ref1 = 3;
*&value = 4;
const *short const p3;
}
```
## e) ***Исправленный код*** 
```cpp
#include <iostream>
int main() {
    short value = 0;
    short value1(3);
    value = 4;
    const short ref2 = 78;
    const short *const p3 = &value1;

    std::cout << "Value: " << value << std::endl;
    std::cout << "Value1: " << value1 << std::endl;
    std::cout << "Ref2: " << ref2 << std::endl;
    std::cout << "*p3: " << *p3 << std::endl;

    return 0;
}
```
## Программа выведет:
### Value: 4
### Value1: 3
### Ref2: 78
# ****************************************
## f) ***Неправильный код.***
```cpp
int main() {
short value = 13;
short value_1 = 100;
short *ptr = &value;
std::cout << &value << '\n';
std::cout << (value +=1) << '\n';
ptr = 9;
std::cout << (value = value_1 + *ptr) << '\n';
std::cout << "Результат: " << value << '\n';
}
```
## f) ***Исправленный код*** 
```cpp
#include <iostream>
int main() {
    short value = 13;
    short value_1 = 100;
    short *ptr = &value;
    std::cout << &value << '\n';
    std::cout << (value += 1) << '\n';
    short temp = 9;
    ptr = &temp;
    std::cout << (value = value_1 + *ptr) << '\n';
    std::cout << "Результат: " << value << '\n';
    return 0;
}
```
## Программа выведет:
### 0x61fe86
### 14
### 109
### Результат: 109
# ****************************************
# Исправьте ошибки можно что-то добавлять а удалять нельзя.
## g) ***Неправильный код.***
```cpp
int main() {
int value1 45;
int value 63;
int *ptr = &value;
*ptr = &value;
ptr = value;
std::cout << "Результат value1 + value2 : " << value1 + ptr << '\n';
}
```
## g) ***Исправленный код*** 
```cpp
#include <iostream>
int main() {
    int value1 = 45;
    int value2 = 63;
    int *ptr = &value2;
    *ptr = value2;
    ptr = &value2;
    std::cout << "Результат value1 + value2 : " << value1 + *ptr << '\n';
    return 0;
}
```
# ****************************************
# Исправьте ошибки можно что-то добавлять а удалять нельзя. Что выведет программа:
## a) ***Неправильный код.***
```cpp
int main() {
std::cout << "Hi !\n";
exit;
std::cout << 3
}
```
## a) ***Исправленный код*** 
```cpp
#include <iostream>
#include <cstdlib>
int main() {
    std::cout << "Hi !\n";
    exit(0); 
    std::cout << 3; 
    return 0; 
}
```
## Программа выведет:
### Hi !
# ****************************************
## b) ***Неправильный код.***
```cpp
int main() {
switch (2) {
case 1
std::cout << 1 << '\n';
case 2
std::cout << 2 << '\n'
case
std::cout << 3 << '\n';
case 4
std::cout << 4 << '\n'
default:
std::cout << 5 << '\n';
```
## b) ***Исправленный код*** 
```cpp
#include <iostream>
int main() {
    switch (2) {
        case 1:
            std::cout << 1 << '\n';
            break; 
        case 2:
            std::cout << 2 << '\n';
            break; 
        case 3: 
            std::cout << 3 << '\n';
            break; 
        case 4:
            std::cout << 4 << '\n';
            break; 
        default:
            std::cout << 5 << '\n';
    }
    return 0;
}
```
## Программа выведет:
### 2
# ****************************************
## с) ***Неправильный код.***
```cpp
#include <iostream>
const int size = 5;
void Func(int ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << ptr[i] << '\n'; // вывод элементов масива в цикле
ptr = 5; // первому элементу массива присваиваем значение 5
std::cout << '\n';
for (int i = 0; i < size; ++i)
std::cout << *ptr++ << '\n'; // вывод элементов масива в цикле
*ptr = 55; // первому элементу массива присваиваем значение 55
std::cout << '\n';
}
int main() {
int array[];
Func(array, size);
for (int i = 0; i < size; ++i)
std::cout << array[i] << '\n';
}
```
## с) ***Исправленный код*** 
```cpp
#include <iostream>

const int size = 5;

void Func(int *ptr, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << ptr[i] << '\n'; // вывод элементов массива

    ptr[0] = 5; // первому элементу массива присваиваем значение 5

    std::cout << '\n';

    for (int i = 0; i < size; ++i)
        std::cout << *ptr++ << '\n'; // указатель смещается

    ptr = ptr - size; // вернули указатель к началу массива

    *ptr = 55; // безопасное присваивание первому элементу

    std::cout << '\n';
}

int main() {
    int array[size] = {}; // инициализация массива нулями

    Func(array, size);

    for (int i = 0; i < size; ++i)
        std::cout << array[i] << '\n'; // вывод изменённого массива

    return 0;
}
```
## Программа выведет:
### 0
### 0
### 0
### 0
### 0
#
### 5
### 0
### 0
### 0
### 0
#
### 55
### 0
### 0
### 0
### 0




