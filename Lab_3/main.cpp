/* Лабораторная работа №3
 * Группа №318
 * Developer: Хлуденцов П.В.
 * OS: Windows 10 Корпоративная
 * Locale (кодировка): IBM866
 */


#include <iostream>
#include <iomanip> // для std::setprecision, ограничение чисел после запятой

// определения перечислений
enum Animal {
    pig,
    chicken,
    goat,
    cat,
    dog
};

enum Floors {
    Parking,
    FoodCourt,
    Clothing,
    Electronics,
    Cinema,
    KidsZone,
    Entertainment,
    RooftopCafe
};

// функция ввода задания
int nomZad()
{
    std::cout << "Введите номер задания  ";
    int z;
    std::cin >> z;
    std::cout << '\n';
    return z;
}

// функция задания 1
void task_1()
{
    // Задание 1а

    std::cout << "Задание №1 \n";
    std::cout << '\n';
    // всего количества карт
    const int total_cardc = 52;
    // количество тузов
    const int aces = 4;
    // вероятность
    double probability_kar = static_cast<double>(aces)/total_cardc;
    std::cout << "А) ";
    std::cout << "Вероятность вытащить туза из колоды в 52 карты = " << probability_kar;
    std::cout << " в процентах " << std::setprecision(3) << probability_kar*100 << " % \n";
    std::cout << '\n';

    // Задание 1б

    // общее количество исходов
    const int total_quantity = 36;
    // количество благоприятных исходов
    const int favorable_quantity = 6;
    // вероятность
    double probability_kos = static_cast<double>(favorable_quantity)/total_quantity;
    std::cout << "B) ";
    std::cout << "Вероятность того, что сумма выпавших очков будет равна 7 = " << probability_kos;
    std::cout << " в процентах " << std::setprecision(3) << probability_kos*100 << " % \n";
    std::cout << '\n';

    // Задание 1с

    // общее количество перестановок
    const int total_quantityPer = 6; // 4! / (2! * 2!) = 6
    // количество благоприятных исходов
    const int favorable_outcomes = 1; // так как только одно слово
    // вероятность
    double probability_buk = static_cast<double>(favorable_outcomes) / total_quantityPer;
    std::cout << "С) ";
    std::cout << "Вероятность того, что при случайном расположении букв получится слово <<МАМА>> = ";
    std::cout << probability_buk << " в процентах " <<  std::setprecision(3) << probability_buk*100 << " % \n";
    std::cout << '\n';
}

// функция задания 2
void printChar(int a = 'a', char b = 'b', char c = 'c', char d = 'd')
{
    std::cout << "a: " << static_cast<char>(a) << ", b: " << b << ", c: " << c << ", d: " << d << '\n';
}

// прототип функция задания 3
int globalValue = 10; // Глобальная переменная

// Прототип функции с использованием trailing
auto initializeVariables() -> void;

// функции задания 4
    // функция, принимающая аргумент типа Animal
void getAnimalName(Animal animal) {
    switch (animal) {
        case pig:
            std::cout << "Animal: Pig" << '\n';
            break;
        case chicken:
            std::cout << "Animal: Chicken" << '\n';
            break;
        case goat:
            std::cout << "Animal: Goat" << '\n';
            break;
        case cat:
            std::cout << "Animal: Cat" << '\n';
            break;
        case dog:
            std::cout << "Animal: Dog" << '\n';
            break;
        default:
            std::cout << "Error: Unknown animal!" << '\n';
    }
}

void printNumberOfLegs(Animal animal) {
    switch (animal) {
        case pig:
            std::cout << "Number of legs: 4" << '\n';
            break;
        case chicken:
            std::cout << "Number of legs: 2" << '\n';
            break;
        case goat:
            std::cout << "Number of legs: 4" << '\n';
            break;
        case cat:
            std::cout << "Number of legs: 4" << '\n';
            break;
        case dog:
            std::cout << "Number of legs: 4" << '\n';
            break;
        default:
            std::cout << "Error: Unknown animal!" << '\n';
    }
}

// функции задания 5
// функции для поиска максимума и минимума с параметрами типа int
int findMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int findMin(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// Перегрузка функций для параметров типа unsigned short
unsigned short findMax(unsigned short a, unsigned short b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

unsigned short findMin(unsigned short a, unsigned short b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// Перегрузка функций для трех параметров типа int
int findMax(int a, int b, int limit) {
    int maximum;
     // Находим максимум
     if (a > b) {
          maximum = a;
      } else {
          maximum = b;
      }

     // Проверяем, больше ли максимум предела
     if (maximum > limit) {
          return maximum; // Если больше, возвращаем максимум
     } else {
          return limit; // Иначе возвращаем предел
     }
}

int findMin(int a, int b, int limit) {
    int minimum;
    // Находим минимум
    if (a < b) {
         minimum = a;
    } else {
         minimum = b;
    }

    // Проверяем, ниже ли минимум предела
    if (minimum < limit) {
         return minimum; // Если ниже, возвращаем предел
    } else {
         return limit; // Иначе возвращаем найденный минимум
    }
}

// функция задания 6
void task_6()
{
    int x = 50;
    float y = 5.5f;
    double z = 3.3;
    unsigned short k =25;

    // выражение 1) int i = (x + y) * z + k;
            // (x + y) ? x (int) неявно приводится к float, результат float.
            // (x + y) * z ? float * double ? неявно приводится к double.
            // (x + y) * z + k ? k (unsigned short) неявно приводится к double.
            // итог выражения ? double, присваивается в int i ? неявное преобразование

    std::cout << "int x = 50;   float y = 5.5f;   double z = 3.3;   unsigned short k =25;" << '\n';
    std::cout << '\n';

    // с неявным приведением
    int i1 = (x + y) * z + k;  // double -> int (неявно)
    std::cout << "С неявным приведением " << '\n';
    std::cout << "int i = (x + y) * z + k; " << " double -> int; " << "    Результат выражения = " << i1 << '\n';
    // c явным приведением
    int i2 = static_cast<int>( ((x + y) * z) + k );
    std::cout << "С явным приведением " << '\n';
    std::cout << "int i = static_cast<int>( ((x + y) * z) + k ); " << "    Результат выражения = " << i2 << '\n';
    std::cout << '\n';

    // выражение 2) k = x - y / z;
            // y / z ? float / double ? float неявно приводится к double, результат double.
            // x - (y / z) ? int - double ? int неявно приводится к double, результат double.
            // присваиваем в k (unsigned short), т.е. из double в unsigned short ? неявное преобразование.

    // с неявным приведением
    k = x - y / z;  // double -> unsigned short (неявно)
    std::cout << "С неявным приведением " << '\n';
    std::cout << "k = x - y / z; " << "  double -> unsigned short; " << "    Результат выражения = " << k << '\n';
    // c явным приведением
    k = static_cast<unsigned short>( x - y / z );
    std::cout << "С явным приведением " << '\n';
    std::cout << "k = static_cast<unsigned short>( x - y / z ); " << "    Результат выражения = " << k << '\n';
    std::cout << '\n';

    // выражение 3) z = x * y + z / x;
            // x * y ? int * float ? int неявно к float, результат float.
            // z / x ? double / int ? int неявно к double, результат double.
            // cложение: float + double ? float неявно к double, результат double.
            // присваиваем в z (double), тип совпадает.

    // с неявным приведением
    z = x * y + z / x;  // double
    std::cout << "С неявным приведением " << '\n';
    std::cout << "z = x * y + z / x; " << "  double " << "    Результат выражения = " << z << '\n';
    // c явным приведением
    z = static_cast<double>(static_cast<float>(x)*y) + static_cast<double>(z/x);
    std::cout << "С явным приведением " << '\n';
    std::cout << "z = static_cast<double>(x * y) + z / x; " << "    Результат выражения = " << z << '\n';
    std::cout << '\n';

    // выражение 4) unsigned int ui = x / y + k;
            // x / y ? int / float ? int неявно к float, результат float.
            // к float прибавляем k (unsigned short), который неявно приводится к float.
            // итог выражения ? float.
            // присваиваем в unsigned int ? неявное преобразование.

    // с неявным приведением
    unsigned int ui1 = x / y + k;  // float -> unsigned int (неявно)
    std::cout << "С неявным приведением " << '\n';
    std::cout << "unsigned int ui = x / y + k; " << " float -> unsigned int; " << "    Результат выражения = " << ui1 << '\n';
    // c явным приведением
    unsigned int ui2 = static_cast<unsigned int>( x / y + k );
    std::cout << "С явным приведением " << '\n';
    std::cout << "unsigned int ui = static_cast<unsigned int>( x / y + k ); " << "    Результат выражения = " << ui2 << '\n';
    std::cout << '\n';

    // выражение 5) short s = x % (x / y);
            // % оператор применяется только к целочисленным типам.
            // в выражении (x/y) ? деление int на float ? результат будет float.
            // нельзя использовать % с плавающей точкой.
            // чтобы исправить, нужно явно привести (x/y) к целому типу.

    // c явным приведением
    short s = x % static_cast<int>(x / y);
    std::cout << "С явным приведением " << '\n';
    std::cout << "short s = x % static_cast<int>(x / y); " << "    Результат выражения = " << s << '\n';
    std::cout << '\n';
}

// функция задания 7
void numF(Floors floors) {
    switch (floors) {
        case Parking:
            std::cout << "Вы приехали на этаж: Парковка" << '\n';
            break;
        case FoodCourt:
            std::cout << "Вы приехали на этаж: Фудкорт" << '\n';
            break;
        case Clothing:
            std::cout << "Вы приехали на этаж: Отдел одежды" << '\n';
            break;
        case Electronics:
            std::cout << "Вы приехали на этаж: Электроника" << '\n';
            break;
        case Cinema:
            std::cout << "Вы приехали на этаж: Кинотеатр" << '\n';
            break;
        case KidsZone:
            std::cout << "Вы приехали на этаж: Детская зона" << '\n';
            break;
        case Entertainment:
            std::cout << "Вы приехали на этаж: Развлекательный центр" << '\n';
            break;
        case RooftopCafe:
            std::cout << "Вы приехали на этаж: Кафе на крыше" << '\n';
            break;
        default:
            std::cout << "Ошибка: этаж должен быть от 0 до 7." << '\n';
    }
}

// Главная функция
int main()
{
    zapros:
    int n=nomZad();
                        // Задание 1
                        if (n==1){
                            task_1();
                        // Задание 2
                        }
                        else if (n==2){
                            std::cout << "Задание №2 \n";
                            std::cout << '\n';
                            printChar();                  // Вызов без аргументов
                            printChar('x');              // Вызов с одним аргументом
                            printChar('x', 'y');         // Вызов с двумя аргументами
                            printChar('x', 'y', 'z');    // Вызов с тремя аргументами
                            printChar('w', 'x', 'y', 'z');// Вызов со всеми четырьмя аргументами
                            std::cout << '\n';
                        }
                        // Задание 3
                        else if (n==3){
                            std::cout << "Задание №3 \n";
                            std::cout << '\n';
                            initializeVariables();
                             // Локальная переменная с тем же именем
                             int globalValue = 20; // Локальная переменная

                             std::cout << "Глобальная переменная: " << ::globalValue << '\n'; // Используем :: для доступа к глобальной переменной
                             std::cout << "Локальная переменная: " << globalValue << '\n'; // Локальная переменная
                             std::cout << '\n';
                        }
                        //Задание 4
                        else if (n==4){
                            std::cout << "Задание №4 \n";
                            std::cout << '\n';
                            // создаем переменную типа Animal и присваиваем ей значение
                            Animal myAnimal = static_cast<Animal>(2);

                            // вызываем функции с аргументом myAnimal
                            getAnimalName(myAnimal);
                            printNumberOfLegs(myAnimal);
                            std::cout << '\n';
                        }
                        //Задание 5
                        else if (n==5){
                            std::cout << "Задание №5 \n";
                            std::cout << '\n';

                            int num1, num2;
                            std::cout << "Введите два числа (int): \n";
                            std::cin >> num1 >> num2;
                            // Вычисление максимума и минимума
                            int maxInt = findMax(num1, num2);
                            int minInt = findMin(num1, num2);
                            std::cout << "Максимум: " << maxInt << '\n';
                            std::cout << "Минимум: " << minInt << '\n';
                            std::cout << '\n';

                            unsigned short ushort1, ushort2;
                            std::cout << "Введите два числа (unsigned short): \n";
                            std::cin >> ushort1 >> ushort2;
                            // Вычисление максимума и минимума для unsigned short
                            unsigned short maxUShort = findMax(ushort1, ushort2);
                            unsigned short minUShort = findMin(ushort1, ushort2);
                            std::cout << "Максимум (unsigned short): " << maxUShort << '\n';
                            std::cout << "Минимум (unsigned short): " << minUShort << '\n';
                            std::cout << '\n';

                            // Ввод трех чисел для ограничения
                            int limitMax, limitMin, num3;

                            std::cout << "Введите три числа ( max, min и порог ограничения): \n";
                            std::cin >> limitMax >> limitMin >> num3;
                            // Вычисление максимума и минимума с учетом порога ограничения
                            int constrainedMax = findMax(limitMax, limitMin, num3);
                            int constrainedMin = findMin(limitMax, limitMin, num3);
                            std::cout << "Максимум с учетом порога: " << constrainedMax << '\n';
                            std::cout << "Минимум с учетом порога: " << constrainedMin << '\n';
                            std::cout << '\n';
                        }
                        //Задание 6
                        else if (n==6){
                            std::cout << "Задание №6 \n";
                            std::cout << '\n';
                            task_6();
                        }
                        //Задание 7
                        else if (n==7){
                            std::cout << "Задание №7 \n";
                            std::cout << '\n';
                            std::cout << "Добро пожаловать в виртуальный торгово-развлекательный центр!\n";


                            floor:
                            std::cout << "\nВведите этаж (0-7), куда хотите поехать:\n";
                            std::cout << "0 - Парковка \n";
                            std::cout << "1 - Фудкорт \n";
                            std::cout << "2 - Отдел одежды \n";
                            std::cout << "3 - Электроника \n";
                            std::cout << "4 - Кинотеатр \n";
                            std::cout << "5 - Детская зона \n";
                            std::cout << "6 - Развлекательный центр \n";
                            std::cout << "7 - Кафе на крыше \n";
                            std::cout << '\n';

                            int floorInput;
                            std::cin >> floorInput;
                            std::cout << '\n';

                            Floors myFloors = static_cast<Floors>(floorInput);
                                numF(myFloors);
                                // Спрашиваем пользователя о выходе из центра
                            std::cout << "\nХотите ли вы выйти из торгового центра? (да/нет): ";

                            std::string bukv; // строка для хранения ответа пользователя
                            std::cin >> bukv;


                                if (bukv == "да") {
                                    std::cout << "\nСпасибо за посещение! До свидания!\n";
                                    std::cout << '\n';
                                } else if (bukv == "нет") {
                                    goto floor; // Продолжаем цикл для следующей поездки
                                } else {
                                    std::cout << "Ответ не распознан. Продолжаем поездки.\n";
                                    std::cout << '\n';
                                    goto floor; // Продолжаем цикл для следующей поездки
                                }
                        }
                        else {
                          std::cout << "Задания с таким номером нет \n";
                          std::cout << '\n';
                        }
goto zapros;

return 0;
}

// определение функции задание 3
void initializeVariables() {
    // Копирующая инициализация
    int iValue = 5;          // Копирующая инициализация
    bool cValue = true;     // Копирующая инициализация
    char charValue = 'A';   // Копирующая инициализация
    long lValue = 100000L;   // Копирующая инициализация

    std::cout << "Copy Initialization:" << '\n';
    std::cout << "iValue: " << iValue << '\n';
    std::cout << "cValue: " << cValue << '\n';
    std::cout << "charValue: " << charValue << '\n';
    std::cout << "lValue: " << lValue << '\n';
    std::cout << '\n';

    // Прямая инициализация
    int iDirectInit(10);          // Прямая инициализация
    bool cDirectInit(false);      // Прямая инициализация
    char charDirectInit('B');     // Прямая инициализация
    long lDirectInit(200000L);     // Прямая инициализация

    std::cout << "Direct Initialization:" << '\n';
    std::cout << "iDirectInit: " << iDirectInit << '\n';
    std::cout << "cDirectInit: " << cDirectInit << '\n';
    std::cout << "charDirectInit: " << charDirectInit << '\n';
    std::cout << "lDirectInit: " << lDirectInit << '\n';
    std::cout << '\n';

    // Унифицированная инициализация
    int iUniformInit{15};          // Унифицированная инициализация
    bool cUniformInit{true};       // Унифицированная инициализация
    char charUniformInit{'C'};     // Унифицированная инициализация
    long lUniformInit{300000L};     // Унифицированная инициализация

    std::cout << "Uniform Initialization:" << '\n';
    std::cout << "iUniformInit: " << iUniformInit << '\n';
    std::cout << "cUniformInit: " << cUniformInit << '\n';
    std::cout << "charUniformInit: " << charUniformInit << '\n';
    std::cout << "lUniformInit: " << lUniformInit << '\n';
    std::cout << '\n';

    // Инициализация с использованием auto
    auto iAuto = 25;          // Инициализация с использованием auto
    auto cAuto = false;      // Инициализация с использованием auto
    auto charAuto = 'D';     // Инициализация с использованием auto
    auto lAuto = 400000L;     // Инициализация с использованием auto

    std::cout << "Auto Initialization:" << '\n';
    std::cout << "iAuto: " << iAuto << '\n';
    std::cout << "cAuto: " << cAuto<< '\n';
    std :: cout<< "charAuto : "<<charAuto<< '\n';
    std :: cout<<	"lAuto : "<<lAuto<< '\n';
    std::cout << '\n';
}
