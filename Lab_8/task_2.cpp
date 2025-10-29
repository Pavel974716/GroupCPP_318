#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdlib>
#include <ctime>

// Задание (а)
/* Берёт вектор и список, заменяет элементы вектора на чётных
   позициях (2,4,6,...) на элементы списка, стоящие на нечётных
   позициях (1,3,5,...). */
std::vector<int> mix_even_positions_with_odd_positions(const std::vector<int>& v, const std::list<int>& lst)
{
    // Собираем элементы списка на нечётных позициях
    std::vector<int> oddPosFromList;
    int pos = 1; // 1-based индекс
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it, ++pos) {
        if (pos % 2 == 1)
            oddPosFromList.push_back(*it);
    }

    // Заменяем элементы вектора на чётных позициях (1-based)
    std::vector<int> res = v;
    std::size_t k = 0;
    for (std::size_t i = 0; i < res.size(); ++i) {
        if ((i + 1) % 2 == 0 && k < oddPosFromList.size()) {
            res[i] = oddPosFromList[k++];
        }
    }
    return res;
}

// Универсальная функция печати контейнера (const-ссылки)
template<class Container>
void print_one_line(const char* const header, const Container& c)
{
    std::cout << header << '\n';
    bool first = true;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (!first) std::cout << ' ';
        std::cout << *it;
        first = false;
    }
    std::cout << '\n';
}

// Задание (b)
// Добавляет в конец списка<double> элемент, равный среднему арифметическому всех его элементов.
void append_mean_tail(std::list<double>& ld)
{
    if (ld.empty()) {
        ld.push_back(0.0);
        return;
    }

    long double sum = 0.0L;
    std::size_t n = 0;

    for (std::list<double>::const_iterator it = ld.begin(); it != ld.end(); ++it) {
        sum += *it;
        ++n;
    }

    const double mean = static_cast<double>(sum / static_cast<long double>(n));
    ld.push_back(mean);
}

// Задание (c)
// Считывает 3 пары (номер, строка) и сортирует их по номеру.
void read_and_print_top3_berries()
{
    std::cout << "Данная программа собирает топ-3 Ваших любимых ягод.\n";

    std::vector<std::pair<int, std::string>> items;
    items.reserve(3);

    for (int i = 0; i < 3; ) {
        std::cout << "Пожалуйста, введите рейтинг: ";
        int rank;
        if (!(std::cin >> rank)) {
            std::cout << "Ошибка ввода рейтинга. Повторите.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Пожалуйста, введите название ягоды: ";
        std::string name;
        std::getline(std::cin, name);

        if (name.empty()) {
            std::cout << "Название пустое. Повторите.\n\n";
            continue;
        }

        items.push_back(std::make_pair(rank, name));
        ++i;
    }

    std::stable_sort(items.begin(), items.end(),
        [](const std::pair<int, std::string>& a,
           const std::pair<int, std::string>& b) {
            return a.first < b.first;
        });

    std::cout << "Топ-3 Ваших любимых ягод:\n";
    for (std::size_t i = 0; i < items.size(); ++i) {
        std::cout << (i + 1) << ". " << items[i].second
                  << " (рейтинг: " << items[i].first << ")\n";
    }
}

// Главная функция Task_2
void Task_2()
{
    std::srand(static_cast<unsigned int>(std::time(0))); // инициализация генератора

    // Задание (a)
    std::cout << "a) чётные позиции вектора и нечётные позиции списка.\n";

    const int nVec = 15;   // неизменяемое количество элементов
    const int nList = 15;

    std::vector<int> myVector;
    std::list<int> myList;

    // Заполняем псевдослучайными числами [-50, 50]
    for (int i = 0; i < nVec; ++i)
        myVector.push_back(std::rand() % 101 - 50);

    for (int i = 0; i < nList; ++i)
        myList.push_back(std::rand() % 101 - 50);

    print_one_line("myVector:", myVector);
    print_one_line("myList:", myList);

    const std::vector<int> mixed = mix_even_positions_with_odd_positions(myVector, myList);
    print_one_line("Смешанный вектор:", mixed);

    // Задание (b)
    std::cout << "\nb) добавление среднего арифметического в конец списка\n";

    std::list<double> ld;
    const int count = 10; // фиксированное количество элементов (до 10)

    for (int i = 0; i < count; ++i) {
        const double val = (std::rand() % 1000) / 10.0 - 50.0; // случайные [-50.0, 50.0]
        ld.push_back(val);
    }

    print_one_line("Список (до):", ld);
    append_mean_tail(ld);
    print_one_line("Список (после добавления среднего):", ld);

    // Задание (c)
    std::cout << "\nc) сортировка трёх любимых ягод\n";
    read_and_print_top3_berries();
}


