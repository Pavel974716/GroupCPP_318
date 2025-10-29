#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <iomanip>
#include <limits>

// Безопасный ввод целого числа в заданном диапазоне
void in_int(const std::string& prompt, int& var, int min = 1, int max = 1000) {
    while (true) {
        std::cout << prompt;
        if (std::cin >> var) {
            if (var >= min && var <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; // корректное значение
            } else {
                std::cout << "Ошибка! Число должно быть в диапазоне от "
                          << min << " до " << max << ".\n\n";
            }
        } else {
            std::cout << "Ошибка! Введите целое число!\n\n";
            std::cin.clear(); // сброс флагов ошибки
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очистка буфера
    }
}

// Перегрузка оператора вывода для std::vector<int>
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    const std::size_t per_line = 10;
    for (std::size_t i = 0; i < v.size(); ++i) {
        out << std::setw(11) << v[i] << ' ';
        if ((i + 1) % per_line == 0) out << '\n';
    }
    return out;
}

// Шаблонная функция для вывода контейнера
template <typename Container>
void printContainer(const Container& cont) {
    std::cout << "Прямой порядок:\n";
    for (auto it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << ' ';

    std::cout << "\nОбратный порядок:\n";
    for (auto rit = cont.rbegin(); rit != cont.rend(); ++rit)
        std::cout << *rit << ' ';

    std::cout << '\n';
}

// Главная функция Task_1
void Task_1() {

    // Задание (a)
    std::cout << "a) генерация контейнера, вывод, подсчёт уникальных \n";

    // Считываем количество элементов (с защитой)
    int N = 0;
    in_int("Введите количество элементов N (от 1 до 1000): ", N, 1, 1000);

    // Настраиваем генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-2000000000, 2000000000);

    // Генерируем контейнер
    std::vector<int> data;
    data.reserve(static_cast<std::size_t>(N));
    for (int i = 0; i < N; ++i)
        data.push_back(dist(gen));

    // Выводим содержимое контейнера (по 10 элементов в строке)
    std::cout << "Содержимое контейнера:\n";
    std::cout << data << '\n';

    // Подсчитываем количество уникальных элементов
    std::set<int> unique_values(data.begin(), data.end());
    std::cout << "Уникальных чисел: " << unique_values.size() << '\n';

    // Задание (b)
    std::cout << "\nb) вывод контейнера в прямом и обратном порядке \n";
    printContainer(data);
}


