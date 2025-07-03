# **3 Тестовые задания**
## 1) ***Найдите ошибку в потере данных, измените код чтобы не было потери данных:***
```cpp
#include<iostream>
int main() {
float a=3.14;
char *pj;
pj = (char*)&a;
std::cout << *pj << '\n';
}
```
## 1) ***Исправленный код***
```cpp
#include <iostream>
#include <iomanip>

int main() {
    float a = 3.14f;
    unsigned char *pj = reinterpret_cast<unsigned char*>(&a);

    // Печатаем все байты числа a
    for (size_t i = 0; i < sizeof(a); ++i) {
        std::cout << "Byte " << i << ": 0x"
                  << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(pj[i]) << std::endl;
    }
    return 0;
}
```
# ****************************************
## 2) ***Исправьте ошибки в программе и реализуйте вывод значение и адрес объекта a через указатели pj и pk:***
```cpp
int main(){
int a=10, *pj;
void *pk;
pj = pk = &a;
pj++;
k++;
std::cout << pk << '\n';
std::cout << pj << '\n'
}
```
## 2) ***Исправленный код*** 
```cpp
#include <iostream>

int main() {
    int a = 10;
    int *pj;
    void *pk;

    pj = &a;          // pj указывает на a
    pk = &a;          // pk также указывает на a

    std::cout << "Значение через pj: " << *pj << '\n';
    std::cout << "Адрес через pj: " << pj << '\n';

    std::cout << "Значение через pk (через приведение типа): " << *(static_cast<int*>(pk)) << '\n';
    std::cout << "Адрес через pk: " << pk << '\n';

    return 0;
}
```
# ****************************************
## 3) ***Помогите другу разработчику доработайте или исправьте код, который сделал:***
```cpp
#include <iostream>
using namespace std;
struct phone{
int kod ;
int nom ;
int mom_abon ;
};
struct new_phone{
int kod1;
int nom1;
int mom_abon1;
};
int main() {
setlocale (LC_ALL, "rus" );
phone object;
new_phone new_object;
wcout << L"Введите код города, номер станции и номер абонента: ";
int mas_all[11];
cin >> mas_all[11];
int mas_a[2];
mas_a[0] = mas_all[0];
mas_a[1] = mas_all[1];
mas_a[2] = mas_all[2];
new_object.kod1 = mas_a[2];
int mas_b[2];
mas_b[0] = mas_all[4];
mas_b[1] = mas_all[5];
mas_b[2] = mas_all[6];
new_object.nom1 = mas_b[2];
int mas_c[3];
mas_c[0] = mas_all[8];
mas_c[1] = mas_all[9];
mas_c[2] = mas_all[10];
mas_c[3] = mas_all[11];
new_object.mom_abon1= mas_b[2];
object.kod = 123;
object.nom = 456;
object.mom_abon = 7890;
wcout << L"Мой номер телефона : " << object.kod << " " << object.nom << " " << object.mom_abon << endl;
wcout << L"Ваш номер : " << new_object.kod1 << " " << new_object.nom1 << " " << new_object.mom_abon1 << endl;
}
```
## 3) ***Исправленный код*** 
```cpp
#include <iostream>
using namespace std;

struct phone {
    int kod;         // код города
    int nom;         // номер станции
    int mom_abon;    // номер абонента
};

int main() {
    setlocale(LC_ALL, "ru_RU.IBM866");

    // Инициализация номера вручную
    phone my_phone = {212, 767, 8900};

    // Объявление переменной для пользовательского ввода
    phone your_phone;

    cout << "Введите код города, номер станции и номер абонента: ";
    cin >> your_phone.kod >> your_phone.nom >> your_phone.mom_abon;

    // Вывод обоих номеров в нужном формате
    cout << "Мой номер: (" << my_phone.kod << ") " << my_phone.nom << "-" << my_phone.mom_abon << endl;
    cout << "Ваш номер: (" << your_phone.kod << ") " << your_phone.nom << "-" << your_phone.mom_abon << endl;

    return 0;
}
```
# ****************************************
## 4) ***Найдите 2е ошибки и измените код чтобы он был рабочим:***
```cpp
#include <iostream>
using namespace std;
int main() {
setlocale (LC_ALL, "rus" );
const int n = 5;
const int m = 10;
int *a;
int *b;
a = new int*[n];
b = new int*[n];
for (int i = 0; i < n; i++) {
a[i] = new int[m];
b[i] = new int[m];
cout << &a[i][0] << endl;
cout << &b[i][0] << endl;
}
}
```
## 4) ***Исправленный код*** 
```cpp
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    const int n = 5;
    const int m = 10;

    int **a;
    int **b;

    a = new int*[n];
    b = new int*[n];

    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
        b[i] = new int[m];
        cout << &a[i][0] << endl;
        cout << &b[i][0] << endl;
    }

    // Очистка памяти
    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}
```
# ****************************************
## 5) ***Найдите ошибки и измените код чтобы он был рабочим и выведите все строки заданные разными способами:***
```cpp
#include <iostream>
using namespace std;
int main() {
char s[] = "char s[]: text";
char* ps = "char* ps: text";
std::string str = "std::string str: text";
s = "another text";
str = "std::string str: another text";
char *s_1 = "char *s_1: text";
const char *s_2 = "const char *s_2: text";
wcout << "Вывод строк : "
}
```
## 5) ***Исправленный код*** 
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    char s[] = "char s[]: text"; // Массив char, менять нельзя напрямую
    const char* ps = "char* ps: text"; // Строковый литерал — const
    string str = "std::string str: text"; // Строка std::string

    const char* s_1 = "char *s_1: text";
    const char* s_2 = "const char *s_2: text";

    // Вывод всех строк до изменения
    cout << "Вывод строк до изменения:" << endl;
    cout << s << endl;
    cout << ps << endl;
    cout << str << endl;
    cout << s_1 << endl;
    cout << s_2 << endl;

    // Изменение строки std::string
    str = "std::string str: another text";

    // Вывод строки после изменения
    cout << "\nВывод строки str после изменения:" << endl;
    cout << str << endl;

    return 0;
}
```
# ****************************************
## 6) ***Исправьте чтобы был следующий вывод, причем нельзя использовать при выводе строку s а использовать s1-s4 (изменить код программы где вопросы примерно так s1 = s.substr(0, 3)):Кто вы по профессии? : Я инженер-программист!***
```cpp
int main() {
wstring s = "I'am an developer";
wstring
s1 = s.substr(????),
s2 = s.substr(????),
s3 = s.substr(?),
s4 = s.substr(????);
wcout << "Why is you? : " << s1 s2+s3+s4 << '\n';
}
```
## 6) ***Исправленный код*** 
```cpp
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main() {    
    setlocale(LC_ALL, "Russian");

    wstring s = L"Кто вы по профессии? : Я инженер-программист!";
    wstring
     s1 = s.substr(0, 21),  // "Кто вы по профессии? : "
     s2 = s.substr(21, 2),  // "Я "
     s3 = s.substr(23, 9),  // "инженер-"
     s4 = s.substr(32);     // "программист!"

    wcout << s1 << s2 << s3 << s4 << '\n';

    return 0;
}
```
# ****************************************