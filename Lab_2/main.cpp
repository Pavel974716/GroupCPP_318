/* Лабораторная работа №2
 * Группа №318
 * Developer: Хлуденцов П.В.
 * OS: Windows 10 Корпоративная
 * Locale (кодировка): IBM866
 */


// Подключаем библиотеку для ввода/вывода
#include <iostream>
#include <bitset>
#include <cmath>
enum kon_en
{
    kon_en1 = 5,
    kon_en2 = 4,
    kon_en3 = 3,
    kon_en4 = 2,
    kon_en5 = 6,
    kon_en6 = 7,
};

// main - главная функция с которой начинается исполнение программы
int main()
{

// Задание 1
std::cout << "Задание №1 \n";
std::cout << '\n';
// Переменная возраста, ввод возраста годпми без месяцев
int Vozrast;
std::cout << "Введите возраст и нажмите Enter \n";
std::cin >> Vozrast;
// Переменная веса
float Ves;
std::cout << "Введите вес в килограммах и нажмите Enter \n";
std::cin >> Ves;
// Переменная роста
float Rost;
std::cout << "Введите рост в сантиметрах и нажмите Enter \n";
std::cin >> Rost;
// Переменная пола (мужчина или женщина)
bool Pol;
std::cout << "Введите 1 если мужчина, 0 если женщина, и нажмите Enter \n";
std::cin >> Pol;
std::cout << "Подсчет идеального веса \n";

if (Pol==1)
   {
   std::cout << "а) - по формуле Брока для мужчин = " << (Rost-100.0f)*0.9f << '\n';
   }
if (Pol==0)
   {
    std::cout << "а) - по формуле Брока для женщин = " << (Rost-100.0f)*0.85f << '\n';
   }
// расчет индекса массы тела
float Index = Ves/(Rost*0.01f*Rost*0.01f);
std::cout << "b) - идеальный вес по индексу массы тела = " << Index << '\n';
// установка диагноза по индексу массы тела
if (Index<16.0f)
   {
    std::cout << "Диагноз: Выраженый дефицит массы \n";
   }
if (16.0f<Index && Index<18.5f)
   {
    std::cout << "Диагноз: Недостаточная (дефицит) массы тела \n";
   }
if (18.5f<Index && Index<25.0f)
   {
    std::cout << "Диагноз: Норма \n";
   }
if (25.0f<Index && Index<30.0f)
   {
    std::cout << "Диагноз: Избыточная масса тела (предожирение) \n";
   }
if (30.0f<Index && Index<35.0f)
   {
    std::cout << "Диагноз: Ожирение первой степени \n";
   }
if (35.0f<Index && Index<40.0f)
   {
    std::cout << "Диагноз: Ожирение второй степени \n";
   }
if (40.0f<Index)
   {
    std::cout << "Диагноз: Ожирение третьей степени (морбидное) \n";
   }
// диагноз по идексу массы с учетом возраста.
std::cout << "c) - по индексу массы тела с учетом возраста \n";
// диагноз по идексу массы с учетом возраста для мужчин.
if (Pol==1)
   {
   if (19<=Vozrast && Vozrast<=24)
      {
       if (Index<21.4f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>26.4f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (21.4f<Index && Index<26.4f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (25<=Vozrast && Vozrast<=34)
      {
       if (Index<21.6f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>26.6f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (21.6f<Index && Index<26.6f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (35<=Vozrast && Vozrast<=44)
      {
       if (Index<22.9f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>27.9f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (22.9f<Index && Index<27.9f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (45<=Vozrast && Vozrast<=54)
      {
       if (Index<25.8f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>30.8f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (25.8f<Index && Index<30.8f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (55<Vozrast)
      {
       if (Index<26.6f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>31.6f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (26.6f<Index && Index<31.6f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   }
// диагноз по идексу массы с учетом возраста для женщин.
if (Pol==0)
   {
   if (19<=Vozrast && Vozrast<=24)
      {
       if (Index<19.5f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>24.5f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (19.5f<Index && Index<24.5f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (25<=Vozrast && Vozrast<=34)
      {
       if (Index<23.2f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>28.2f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (23.2f<Index && Index<28.2f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (35<=Vozrast && Vozrast<=44)
      {
       if (Index<23.4f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>28.4f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (23.4f<Index && Index<28.4f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (45<=Vozrast && Vozrast<=54)
      {
       if (Index<25.2f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>30.2f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (25.2f<Index && Index<30.2f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   if (55<Vozrast)
      {
       if (Index<27.3f)
          {
           std::cout << "Диагноз: дефицит массы тела \n";
          }
       if (Index>32.3f)
          {
           std::cout << "Дигноз: проблемма с лишним весом \n";
          }
       if (27.3f<Index && Index<32.3f)
          {
           std::cout << "Диагноз: вес в норме \n";
          }
      }
   }
std::cout << '\n';

// Задание 2
// Задание 2.1
std::cout << "Задание №2 \n";
std::cout << '\n';
std::cout << "bool:\t" << sizeof(bool) << " bytes; \n";
std::cout << "int:\t" << sizeof(int) << "bytes; \n";
std::cout << "char:\t" << sizeof(char) << "bytes; \n";
std::cout << "float:\t" << sizeof(float) << "bytes; \n";
std::cout << "double:\t" << sizeof(double) << "bytes; \n";
std::cout << '\n';

// Задание 2.2
unsigned int ugint;
std::cout << "unsigned int:\t\t" << sizeof(ugint) << "bytes; \n";
signed int sgint;
std::cout << "signed int:\t\t" << sizeof(sgint) << "bytes; \n";
short int shint;
std::cout << "short int:\t\t" << sizeof(shint) << "bytes; \n";
long int llint;
std::cout << "long int:\t\t" << sizeof(llint) << "bytes; \n";
unsigned char ugchar;
std::cout << "unsigned char:\t\t" << sizeof(ugchar) << " bytes; \n";
signed char sgchar;
std::cout << "signed char:\t\t" << sizeof(sgchar) << "bytes; \n";
unsigned short ugshort;
std::cout << "unsigned short:\t\t" << sizeof(ugshort) << "bytes; \n";
signed short sgshort;
std::cout << "signed short:\t\t" << sizeof(sgshort) << " bytes; \n";
unsigned long uglong;
std::cout << "unsigned long:\t\t" << sizeof(uglong) << "bytes; \n";
signed long sglong;
std::cout << "signed long:\t\t" << sizeof(sglong) << "bytes; \n";
unsigned long long ugllong;
std::cout << "unsigned long long:\t" << sizeof(ugllong) << "bytes; \n";
signed long long sgllong;
std::cout << "signed long long:\t" << sizeof(sgllong) << "bytes; \n";
long double lli;
std::cout << "long double:\t\t" << sizeof(lli) << "bytes; \n";
std::cout << '\n';

// Задание 2.3
std::cout << "unsigned int: \n";
std::cout << std::hex << '\t' << "hex: " << " от "  << 0 << " до " << 65535 << '\n';
std::cout << std::dec << '\t' << "dec: " << " от "  << 0 << " до " << 65535 << '\n';
std::cout << '\t' << "bin: " << " от "  <<  std::bitset <16>(0) << " до " << std::bitset <16>(65535) << '\n';
std::cout << "unsigned char: \n";
std::cout << std::hex << '\t' << "hex: " << " от "  << 0 << " до " << 255 << '\n';
std::cout << std::dec << '\t' << "dec: " << " от "  << 0 << " до " << 255 << '\n';
std::cout << '\t' << "bin: " << " от "  <<  std::bitset <8>(0) << " до " << std::bitset <8>(255) << '\n';
std::cout << "unsigned long: \n";
std::cout << std::hex << '\t' << "hex: " << " от "  << 0 << " до " << 4294967295 << '\n';
std::cout << std::dec << '\t' << "dec: " << " от "  << 0 << " до " << 4294967295 << '\n';
std::cout << '\t' << "bin: " << " от "  <<  std::bitset <32>(0) << " до " << std::bitset <32>(4294967295) << '\n';
std::cout << "unsigned shot: \n";
std::cout << std::hex << '\t' << "hex: " << " от "  << 0 << " до " << 65535 << '\n';
std::cout << std::dec << '\t' << "dec: " << " от "  << 0 << " до " << 65535 << '\n';
std::cout << '\t' << "bin: " << " от "  <<  std::bitset <16>(0) << " до " << std::bitset <16>(4294967295) << '\n';
std::cout << '\n';

// Задание 3
std::cout << "Задание №3 \n";
std::cout << '\n';
// определяем переменные
float a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
std::cout << "Введите 10 чисел с плавающей точкой и нажмите Enter \n";
std::cout << "1 число = ";
std::cin >> a1;
std::cout << "2 число = ";
std::cin >> a2;
std::cout << "3 число = ";
std::cin >> a3;
std::cout << "4 число = ";
std::cin >> a4;
std::cout << "5 число = ";
std::cin >> a5;
std::cout << "6 число = ";
std::cin >> a6;
std::cout << "7 число = ";
std::cin >> a7;
std::cout << "8 число = ";
std::cin >> a8;
std::cout << "9 число = ";
std::cin >> a9;
std::cout << "10 число = ";
std::cin >> a10;
std::cout << "Результат = " << (a1+a2+a3+a4+a5+a6+a7+a8+a9+a10)/10 << '\n';
std::cout << '\n';


// Задание 4
std::cout << "Задание №4 \n";
std::cout << '\n';
double d1 (3.450e1);
std::cout << "Дано 34.50 " << "<3.450e1> " << "Получено = " << d1 << '\n';
double d2 (4000e-6);
std::cout << "Дано 0.004000 " << "<4000e-6> " << "Получено = " << d2 << '\n';
double d3 (1.23005e2);
std::cout << "Дано 123.005 " << "<1.23005e2> " << "Получено = " << d3 << '\n';
double d4 (1.46e5);
std::cout << "Дано 146000 " << "<1.46e5> " << "Получено = " << d4 << '\n';
std::cout << '\n';


// Задание 5
std::cout << "Задание №5 \n";
std::cout << '\n';

// Задание 5.1
//TODO не понял почему подчеркивает true и false???
std::cout << "Задание №5.1 \n";
std::cout << ((true && true) || false) << '\n';
std::cout << ((false && true) || true) << '\n';
std::cout << ((false && true) || false || true) << '\n';
std::cout << ((5 > 6 || 4 > 3) && (7 > 8)) << '\n';
std::cout << (!(7 > 6 || 3 > 4)) << '\n';
std::cout << '\n';

// Задание 5.2
//TODO не понял почему подчеркивает && и || ???
std::cout << "Задание №5.2 \n";
const bool k1 (true);
const bool k2 (true);
const bool k3 (true);
const bool k4 (false);
const bool k5 (false);
const bool k6 (false);
std::cout << ((k1 && k2) || (!k3) && (k4 || k5)) << '\n';
std::cout << ((k1 && k2) || (k3 && k4) || (!k5)) << '\n';
std::cout << ((k1 || k2) && (k3 || k4) && (k4 || k6)) << '\n';
std::cout << "enum \n";
// енум
std::cout << ((kon_en1 > kon_en2) && (kon_en3 < kon_en4) && (kon_en5 != kon_en6)) << '\n';
std::cout << '\n';

// Задание 5.3
std::cout << "Задание №5.3 \n";
bool a (false);
bool b (true);
std::cout << (!(a && b)) << "=" << ((!a) || (!b)) << '\n';
std::cout << (!(a || b)) << "=" << ((!a) && (!b)) << '\n';
std::cout << '\n';

// Задание 5.4
std::cout << "Задание №5.4 \n";
int x, y, z, v;
bool logicValue;
std::cout << "Введите 4 целочисленых числа \n";
// присваивем начальные значения переменным
std::cin >> x >> y >> z >> v;
std::cout << "Введите логическую переменную 0 или 1 \n";
std::cin >> logicValue;
// х - привсваеваеться другое значение сумма чисел
x = 3 + 4 + 5;
std::cout << "x = " << x << "; y = " << y << "; z = " << z << "; v = " << v << '\n';
// x и y присваеваеться значение z
x = y = z;
std::cout << "x = " << x << "; y = " << y << "; z = " << z << "; v = " << v << '\n';
// у увеличиваеться инкрементом (++) на 1, и z назначается начальное значение умноженое (y+1)+5
z *= ++y + 5;
std::cout << "x = " << x << "; y = " << y << "; z = " << z << "; v = " << v << '\n';
logicValue = x || y && z || v;
// x,y любое целочисленое, а z,v должны равны быть нулям
std::cout << "logicValue = " << logicValue << '\n';
std::cout << '\n';


// Задание 5.5
std::cout << "Задание №5.5 \n";
int chislo, stvig, step;
std::cout << "Введите число от 0 до 2 \n";
std::cin >> chislo;
std::cout << "Введите число на которое необходимо сдвинуть от 1 до 11 \n";
std::cin >> stvig;
step = pow (chislo, 4);
std::cout << std::dec << "10-м виде " << (step << stvig) << '\n';
std::cout << std::hex << "16-м виде " << (step << stvig) << '\n';
std::cout << std::oct << "8-м виде " << (step << stvig) << '\n';
std::cout << "2-м виде " <<  std::bitset <16>((step << stvig)) << '\n';
std::cout << '\n';

/* Задание 5.6
int res = a + b * 1 ? 128/5; умножение, деление, сложение, ?
int res = a | b >> 1; побитовый сдвиг вправо,побитовое или
int res = a /b* k; деление, умножение
*/




return 0;
}
