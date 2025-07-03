#include <iostream>
#include <string>
#include <limits> // Для std::numeric_limits
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки
void in_int(const std::string & prompt, int & var); // Функция безопасного ввода целого числа

// Структуры для описания существа с динамическими массивами
struct Head {
    int count;
    std::string *types; // Динамический массив строк
};

struct Eyes {
    int count;
    std::string *types; // Динамический массив строк
};

struct Legs {
    int count;
};

struct Cover {
    std::string description;
};

struct Tail {
    std::string type;
};

struct Creature {
    std::string name; // Название вида
    Head head;
    Legs legs;
    Cover cover;
    Tail tail;
    Eyes eyes;

    // Конструктор по умолчанию
    Creature() : head{0, nullptr}, eyes{0, nullptr} {}

    // Деструктор для освобождения памяти
    ~Creature() {
        delete[] head.types;
        delete[] eyes.types;
    }
};

// Создание нового существа с учетом количества типов
Creature createCreature() {
    Creature creature;

    // Ввод названия вида
    creature.name = in_string("\nВведите название нового вида существа: ");

    // Ввод количества голов
    int headCount;
    in_int("Введите количество голов: ", headCount);
    creature.head.count = headCount;

    // Выделение памяти под типы голов
    if (headCount > 0) {
        creature.head.types = new std::string[headCount];
        for (int i = 0; i < headCount; ++i) {
            creature.head.types[i] = in_string("Введите тип головы #" + std::to_string(i + 1) + ": ");
        }
    } else {
        creature.head.types = nullptr; // Если голов нет
    }

    // Ввод количества лап
    in_int("Введите количество лап: ", creature.legs.count);

    // Описание покрова тела
    creature.cover.description = in_string("Введите описание покрова тела: ");

    // Тип хвоста
    creature.tail.type = in_string("Введите тип хвоста: ");

    // Ввод количества глаз
    int eyesCount;
    in_int("Введите количество глаз: ", eyesCount);
    creature.eyes.count = eyesCount;

    // Выделение памяти под типы глаз
    if (eyesCount > 0) {
        creature.eyes.types = new std::string[eyesCount];
        for (int i = 0; i < eyesCount; ++i) {
            creature.eyes.types[i] = in_string("Введите тип глаза #" + std::to_string(i + 1) + ": ");
        }
    } else {
        creature.eyes.types = nullptr; // Если глаз нет
    }

    return creature;
}

// Функция для отображения информации о существе
void displayCreature(const Creature& c) {
    std::cout << "\n=== Созданный вид ===\n";

    std::cout << "Название: " << c.name << '\n';

    std::cout << "Головы (" << c.head.count << "): ";
    for (int i = 0; i < c.head.count; ++i) {
        std::cout << c.head.types[i] << "; ";
   }
   if (c.head.count == 0) {
       std::cout << "отсутствуют";
   }
   std::cout << '\n';

   std::cout << "Лапы: " << c.legs.count << '\n';
   std::cout << "Покров тела: " << c.cover.description << '\n';
   std::cout << "Хвост: " << c.tail.type << '\n';

   std::cout << "Глаза (" << c.eyes.count << ") типов: ";
   for (int i = 0; i < c.eyes.count; ++i) {
       std::cout << c.eyes.types[i] << "; ";
   }
   if (c.eyes.count == 0) {
       std::cout << "отсутствуют";
   }
   std::cout << '\n';
}

// Главная функция Task_2
void Task_2() {

     // Инициализация генератора случайных чисел
     std::srand(std::time(nullptr));
     std::cout<<"Добро пожаловать! Пора стать создателем нового вида.\n";

     while (true) {
         std::string bukv = in_string("\nХотите создать новое существо? (y/n): ");

         if (bukv == "y" || bukv == "Y") {
             Creature newCreature= createCreature();
             std::cout<<"\nСоздание завершено!\n";
             displayCreature(newCreature);

             // Память для newCreature автоматически освобождается при выходе из функции, так как деструктор вызовется.
             } else if (bukv == "n" || bukv == "N") {
             break;
         } else {
             std::cout << "Ответ не распознан. Пожалуйста, введите 'y' или 'n': \n";
         }
     }
}
