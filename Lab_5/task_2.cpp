#include <iostream>
#include <string>
#include <limits>
#include <new> // для std::nothrow

std::string in_string(const std::string & prompt); // Функция безопасного ввода строки
void in_int(const std::string & prompt, int & var); // Функция безопасного ввода целого числа

// Структуры
struct Head {
    int count = 0;
    std::string *types = nullptr;
};

struct Eyes {
    int count = 0;
    std::string *types = nullptr;
};

struct Legs {
    int count = 0;
};

struct Cover {
    std::string description;
};

struct Tail {
    std::string type;
};

struct Creature {
    std::string name;
    Head head;
    Legs legs;
    Cover cover;
    Tail tail;
    Eyes eyes;

    // Конструктор - ввод данных
    Creature() {
        name = in_string("\nВведите название нового вида существа: ");

        in_int("Введите количество голов: ", head.count);
        if (head.count > 0) {
            head.types = new(std::nothrow) std::string[head.count];
            if (head.types == nullptr) {
                std::cerr << "Ошибка выделения памяти для типов голов!\n";
                head.count = 0;
            } else {
                for (int i = 0; i < head.count; ++i) {
                    head.types[i] = in_string("Введите тип головы #" + std::to_string(i + 1) + ": ");
                }
            }
        }

        in_int("Введите количество лап: ", legs.count);

        cover.description = in_string("Введите описание покрова тела: ");

        tail.type = in_string("Введите тип хвоста: ");

        in_int("Введите количество глаз: ", eyes.count);
        if (eyes.count > 0) {
            eyes.types = new(std::nothrow) std::string[eyes.count];
            if (eyes.types == nullptr) {
                std::cerr << "Ошибка выделения памяти для типов глаз!\n";
                eyes.count = 0;
            } else {
                for (int i = 0; i < eyes.count; ++i) {
                    eyes.types[i] = in_string("Введите тип глаза #" + std::to_string(i + 1) + ": ");
                }
            }
        }
    }

    // Деструктор - освобождение памяти
    ~Creature() {
        if (head.types != nullptr) {
            delete[] head.types;
            head.types = nullptr;
        }
        if (eyes.types != nullptr) {
            delete[] eyes.types;
            eyes.types = nullptr;
        }
    }

    // Метод для вывода информации
    void display() const {
        std::cout << "\n=== Созданный вид ===\n";
        std::cout << "Название: " << name << '\n';

        std::cout << "Головы (" << head.count << "): ";
        if (head.count > 0 && head.types != nullptr) {
            for (int i = 0; i < head.count; ++i)
                std::cout << head.types[i] << "; ";
        } else {
            std::cout << "отсутствуют";
        }
        std::cout << '\n';

        std::cout << "Лапы: " << legs.count << '\n';
        std::cout << "Покров тела: " << cover.description << '\n';
        std::cout << "Хвост: " << tail.type << '\n';

        std::cout << "Глаза (" << eyes.count << "): ";
        if (eyes.count > 0 && eyes.types != nullptr) {
            for (int i = 0; i < eyes.count; ++i)
                std::cout << eyes.types[i] << "; ";
        } else {
            std::cout << "отсутствуют";
        }
        std::cout << '\n';
    }
};

// Главная функция Task_2
void Task_2() {
    std::cout << "Добро пожаловать! Пора стать создателем нового вида.\n";

    Creature* pCreature = nullptr;

    while (true) {
        std::string answer = in_string("\nХотите создать новое существо? (y/n): ");

        if (answer == "y" || answer == "Y") {
            pCreature = new(std::nothrow) Creature();
            if (pCreature == nullptr) {
                std::cerr << "Не удалось выделить память для создания существа!\n";
                continue;
            }

            std::cout << "\nСоздание завершено!\n";
            pCreature->display();

            delete pCreature;
            pCreature = nullptr;

        } else if (answer == "n" || answer == "N") {
            break;
        } else {
            std::cout << "Ответ не распознан. Пожалуйста, введите 'y' или 'n': \n";
        }
    }
}
