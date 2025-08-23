# **3 Тестовые задания**
## 1) ***Найдите ошибки в коде, чтобы программа представленная ниже заработала, можно только добавлять что-то, но убирать нельзя.***
```cpp
#include <iostream>
class Integer {
Integer(int value) {
value=value;
std::cout << "Object created." <;
}
int getValue() return value;
void setValue(int number) { value = number; }
void print( {
cout << "Value: " << value
}
private
int value;
}
int main()
Integer integer;
.setValue(3);
std::cout << Value: " << getValue() <<
}
```
## 1) ***Исправленный код***
```cpp
#include <iostream>

// Добавляем public: для доступа к методам и конструктору
class Integer {
public:
    // Добавляем фигурные скобки, this->value
    Integer(int value) {
        this->value = value;
        std::cout << "Object created." << '\n';
    }

    // Добавляем фигурные скобки
    int getValue() { return value; }

    void setValue(int number) { value = number; }

    // Исправляем синтаксис метода print
    void print() {
        std::cout << "Value: " << value << '\n';
    }

private:
    int value;
}; // Добавлен ; в конце класса

int main() {
    // Добавляем конструктор с аргументом
    Integer integer(0); // или любое другое значение

    integer.setValue(3); // убрали лишнюю точку

    std::cout << "Value: " << integer.getValue() << '\n'; // добавлен объект и исправлен вывод

    return 0;
}
```
# ****************************************
## 2) ***Найдите ошибки в программе, которая будет заниматься учетом успеваемости студентов в группе, чтобы программа представленная ниже заработала, можно только добавлять что-то,но убирать нельзя.***
```cpp
#include <string>
#include <iostream>
class Students {
// Установка имени студента
void set_name(string xstudent_name) {
name = student_name;
}
// Получение имени студента
std::string get_name() {
return name;
// Установка фамилии студента
void set_last_name(std::string student_last_name) {
last_name = student_last_name;
}
// Получение фамилии студента
std::string get_last_name() {
return last_name;
}
// Установка промежуточных оценок
void set_scores(int student_scores[]) {
for (int i = 0; i < 5; +i) {
scores[i] = student_scores[i];
}
}
// Установка среднего балла
void set_average_ball(float ball) {
average_ball = ball
}
// Получение среднего балла
float get_average_ball() {
return average_ball;
}
Students();
private
// Промежуточные оценки
int scores[5];
// Средний балл
float average_ball;
// Имя
std::string name;
// Фамилия
std::string last_name;
}
main() -> int {
// Создание объекта класса Student
Students ;
std::string name;
string last_name;
// Ввод имени с клавиатуры
cout << "Name: «";
getline(std::cin, name);
// Ввод фамилии
std::cout << "Last name: ";
getline(cin, last_name);
// Сохранение имени и фамилии в объект класса Students
student.set_name(name);
student.set_last_name(last_name);
// Оценки
int scores[];
// Сумма всех оценок
int sum = 0;
// Ввод промежуточных оценок
for (i = 0; i < 5; ++i) {
std::cout << "Score " << i+1 << ": ";
std::cin >> scores[i];
// суммирование
sum += scores[i];
}
// Сохраняем промежуточные оценки в объект класса Student
student.set_scores(scores);
// Считаем средний балл
float average_ball = sum / 5,0;
// Сохраняем средний балл в объект класса Students
set_average_ball(average_ball);
// Выводим данные по студенту
std::cout << "Average ball for " << student.get_name() << " "
<< student.get_last_name() << " is "
<< student.get_average_ball() << std::endl;
}
```
## 2) ***Исправленный код*** 
```cpp
#include <string>
#include <iostream>
using namespace std;

class Students {
public:
    // Установка имени студента
    void set_name(string xstudent_name) {
        name = xstudent_name;
    }

    // Получение имени студента
    std::string get_name() {
        return name;
    }

    // Установка фамилии студента
    void set_last_name(std::string student_last_name) {
        last_name = student_last_name;
    }

    // Получение фамилии студента
    std::string get_last_name() {
        return last_name;
    }

    // Установка промежуточных оценок
    void set_scores(int student_scores[]) {
        for (int i = 0; i < 5; ++i) {
            scores[i] = student_scores[i];
        }
    }

    // Установка среднего балла
    void set_average_ball(float ball) {
        average_ball = ball;
    }

    // Получение среднего балла
    float get_average_ball() {
        return average_ball;
    }

    Students() {}

private:
    // Промежуточные оценки
    int scores[5];
    // Средний балл
    float average_ball;
    // Имя
    std::string name;
    // Фамилия
    std::string last_name;
};

int main() {
    // Создание объекта класса Student
    Students student;
    std::string name;
    string last_name;

    // Ввод имени с клавиатуры
    cout << "Name: ";
    getline(std::cin, name);

    // Ввод фамилии
    std::cout << "Last name: ";
    getline(cin, last_name);

    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);

    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок
    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << i+1 << ": ";
        std::cin >> scores[i];
        // суммирование
        sum += scores[i];
    }

    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);

    // Считаем средний балл
    float average_ball = sum / 5.0;

    // Сохраняем средний балл в объект класса Students
    student.set_average_ball(average_ball);

    // Выводим данные по студенту
    std::cout << "Average ball for " << student.get_name() << " "
              << student.get_last_name() << " is "
              << student.get_average_ball() << std::endl;

    return 0;
}
```
# ****************************************
## 3) ***Исправьте ошибки в программе, можно только добавлять что-то, но убирать нельзя:***
```cpp
struct Vec2f {
float x ;
float y ;
float x_1;
float y_1;
Vec2f (float x, float y) x_1(x)
, y_1(y) {
x = x;
y = y;
}
float getLength() const {
const float lengthSquare = x * x + y * y;
return std::sqrt(lengthSquare);
}
}
int main() {
cout << vect2f.getLength() << '\n';
}
```
## 3) ***Исправленный код*** 
```cpp
#include <iostream>
#include <cmath> // для std::sqrt
using namespace std;

struct Vec2f {
    float x;
    float y;
    float x_1;
    float y_1;

    Vec2f(float x, float y) : x_1(x), y_1(y) { // добавлен двоеточие-инициализатор
        this->x = x; // this->, чтобы отличать от параметра
        this->y = y;
    }

    float getLength() const {
        const float lengthSquare = x * x + y * y;
        return std::sqrt(lengthSquare);
    }
}; // добавлена точка с запятой

int main() {
    Vec2f vect2f(3.0f, 4.0f); // добавлено объявление объекта
    cout << vect2f.getLength() << '\n';
}
```
# ****************************************
## 4) ***Исправьте ошибки в программе.***
```cpp
class BufferedIO {
public
enum IOError { None, Access, General, Erro = -1}
class Date {
unsigned short nWeekDay : 3, // 0..7 (3 bits)
unsigned short nMonthDay : 6, // 0..31 (6 bits)
unsigned short nMonth : 5, // 0..12 (5 bits)
unsigned short nYear : 8, // 0..100 (8 bits)
}
// Declare nested class BufferedInput.
class BufferedInput {
BufferedInput();
public
int read() {}
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
// Declare nested class BufferedOutput.
class BufferedOutput {
BufferedOutput();
public:
int Ngood() {
return _inputerror == Erro;
}
private:
int _inputerror;
}
}
int main() {
BufferedIO _inputerror;
BufferedInput buffIn;
BufferedOutput buffOut;
std::cout << _inputerror.nWeekDay << '\n';
}
```
## 4) ***Исправленный код*** 
```cpp
#include <iostream>
using namespace std;

class BufferedIO {
public:
    enum IOError { None, Access, General, Erro = -1 }; // добавлена ; в enum

    class Date {
    public:
        unsigned short nWeekDay : 3;   // добавлены точки с запятой
        unsigned short nMonthDay : 6;
        unsigned short nMonth : 5;
        unsigned short nYear : 8;
    }; // закрытие класса Date

   // Объявление вложенного класса BufferedInput
    class BufferedInput {
    public:
        BufferedInput() {} // определен конструктор
        int read() { return 0; } // добавлен return
        int Ngood() {
            return _inputerror == Erro;
        }
    private:
        int _inputerror = Erro; // добавлена инициализация
    }; // закрытие класса BufferedInput

    // Объявление вложенного класса BufferedOutput
    class BufferedOutput {
    public:
        BufferedOutput() {} // определен конструктор
        int Ngood() {
            return _inputerror == Erro;
        }
    private:
        int _inputerror = Erro;
    }; // закрытие класса BufferedOutput
};

int main() {
    BufferedIO::Date date; // обращение к вложенному классу
    BufferedIO::BufferedInput buffIn; // квалифицированные имена
    BufferedIO::BufferedOutput buffOut;
    std::cout << date.nWeekDay << '\n'; // вывод значения поля
}
```
# ****************************************
## 5) ***Исправьте ошибки в программе и выведите статическую переменную.***
```cpp
class BufferedOutput {
short BytesWritten() {
return bytecount;
}
static void ResetCount() {
bytecount = 0;
}
static long bytecount;
};
int main() {
BufferedOutput bufOut = new BufferedOutput;
std::cout << bufOut.bytecount << '\n';
}
```
## 5) ***Исправленный код*** 
```cpp
#include <iostream>

class BufferedOutput {
public:
    short BytesWritten() const {
        return bytecount;
    }

    static void ResetCount() {
        bytecount = 0;
    }

    static long bytecount;
};

// Определение статической переменной
long BufferedOutput::bytecount = 123; // Можно задать начальное значение

int main() {
    BufferedOutput bufOut;
    std::cout << bufOut.BytesWritten() << '\n';

    return 0;

}
```
# ****************************************
## 5) ***Исправьте ошибки в программе причем нельзя убирать const у функции getFlag(). Программа должна вывести 4.***
```cpp
class X {
X(int flag) : m_flag(flag) {}
bool getFlag() const {
m_accessCount++;
return m_flag + m_accessCount;
}
private:
int m_flag;
int m_accessCount{0};
};
int main() {
X x(new X);
std::cout << x.getFlag << '\n';
}
```
## 5) ***Исправленный код*** 
```cpp
#include <iostream>

class X {
public:
    X(int flag) : m_flag(flag) {}

    int getFlag() const { // <-- Возвращает int, не bool
        m_accessCount++;
        return m_flag + m_accessCount;
    }

private:
    int m_flag;
    mutable int m_accessCount{0}; // mutable позволяет менять даже в const методе
};

int main() {
    X x(3); // 3 + 1 = 4
    std::cout << x.getFlag() << '\n'; // Вывод: 4
}
```
# ****************************************
## 6) ***Исправьте ошибки в программе.***
```cpp
#include <iostream>
using namespace std;
namespace box {
class Box {
double length; // Length of a box
double breadth; // Breadth of a box
double height; // Height of a box
} };
int main() {
Box Box1; // Declare Box1 of type Box
Box Box2; // Declare Box2 of type Box
box::Box Box3(new Box); // Declare Box2 of type Box
double volume = 0.0; // Store the volume of a box here
// box 1 specification
box::Box1.height = 5.0;
box::Box1.length = 6.0;
box::Box1.breadth = 7.0;
// box 2 specification
box::Box2.height = 10.0;
box::Box2.length = 12.0;
box::Box2.breadth = 13.0;
// volume of box 1
volume = box::Box1.height * box::Box1.length * box::Box1.breadth;
cout << "Volume of Box1 : " << volume <<endl;
// volume of box 2
volume = box::Box2.height * box::Box2.length * box::Box2.breadth;
cout << "Volume of Box2 : " << volume <<endl;
delete box::Box3[];
}
```
## 6) ***Исправленный код*** 
```cpp
#include <iostream>
using namespace std;

namespace box {
    // Класс Box представляет коробку с длиной, шириной и высотой
    class Box {
    public:
        double length;  // Длина коробки
        double breadth; // Ширина коробки
        double height;  // Высота коробки
    };
}

int main() {
    // Объявление объектов Box1 и Box2 типа Box из пространства имён box
    box::Box Box1;
    box::Box Box2;

    // Динамическое создание объекта Box3
    box::Box* Box3 = new box::Box;

    double volume = 0.0; // Переменная для хранения объёма

    // Задание параметров для Box1
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    // Задание параметров для Box2
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    // Вычисление объёма Box1
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Объём Box1 : " << volume << endl;

    // Вычисление объёма Box2
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Объём Box2 : " << volume << endl;

    // Освобождение памяти, выделенной для Box3
    delete Box3;

    return 0;
}

```
# ****************************************
## 7) ***Исправьте ошибки. Добавьте операторы * & в объявлении указателя на член класса.***
```cpp
class Window {
public:
Window(); // Default constructor.
Window( int x1, int y1, int x2, int y2 ) {} // Constructor specifying Window size.
bool SetCaption( const char *szTitle ) { return 0; } // Set window caption.
const char *GetCaption() {} // Get window caption.
char *szWinCaption; // Window caption.
};
// Declare a pointer
char Window::*pwCaption = &Window::szWinCaption;
const char * (Window::* pfnwGC)() = Window::GetCaption;
bool (Window:: pfnwSC)( const char * ) = &Window::SetCaption;
Window wMainWindow;
Window pwChildWindow = new Window;
char *szUntitled = "Untitled - ";
int cUntitledLen = strlen(szUntitled);
int main() {
}
```
## 7) ***Исправленный код*** 
```cpp
#include <iostream>  // для std::cout
#include <cstring>   // для strlen

class Window {
public:
    Window() {} // Конструктор по умолчанию.

    // Конструктор с параметрами, подавляем предупреждения о неиспользуемых параметрах
    Window(int x1, int y1, int x2, int y2) {
        (void)x1; (void)y1; (void)x2; (void)y2;
    }

    // Установить заголовок окна
    bool SetCaption(const char *szTitle) {
        szWinCaption = const_cast<char*>(szTitle);
        return true;
    }

    // Получить заголовок окна
    const char *GetCaption() {
        return szWinCaption;
    }

    char *szWinCaption; // Заголовок окна (указатель на строку)
};

// Объявление указателя на член-данное (указатель на char* в классе Window)
char* Window::*pwCaption = &Window::szWinCaption;

// Объявление указателя на функцию-член, возвращающую const char* и не принимающую параметров
const char* (Window::*pfnwGC)() = &Window::GetCaption;

// Объявление указателя на функцию-член, принимающую const char* и возвращающую bool
bool (Window::*pfnwSC)(const char*) = &Window::SetCaption;

int main() {
    Window wMainWindow;              // Создаем объект окна
    Window* pwChildWindow = new Window;  // Создаем объект окна динамически

    char *szUntitled = (char*)"Untitled - ";       // Исходный заголовок
    int cUntitledLen = std::strlen(szUntitled);    // Длина заголовка

    // Присваиваем заголовок через указатель на член-данное
    wMainWindow.*pwCaption = szUntitled;

    // Вызываем метод установки заголовка через указатель на функцию-член
    (wMainWindow.*pfnwSC)("Новое окно");

    // Получаем текущий заголовок через указатель на функцию-член
    const char* cap = (wMainWindow.*pfnwGC)();

    // Выводим длину заголовка и текущий заголовок окна в консоль
    std::cout << "Длина заголовка szUntitled: " << cUntitledLen << '\n';
    std::cout << "Текущий заголовок окна: " << cap << '\n';

    delete pwChildWindow;  // Освобождаем динамически выделенную память

    return 0;
}
```
# ****************************************