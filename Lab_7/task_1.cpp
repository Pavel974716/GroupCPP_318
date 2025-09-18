#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <limits>
#include <stdexcept>

// Функция для безопасного ввода целого числа
void in_int(const std::string & prompt, int & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "Ошибка ввода.\n" << '\n' << prompt;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Главная функция Task_1
void Task_1() {
    try {
        int n;

        // Ввод числа с проверкой диапазона
        while (true) {
            in_int("Введите номер числа Фибоначчи (от 0 до 50): ", n);
            if (n < 0 || n > 50) {
                std::cout << "Ошибка ввода.\n";
            } else {
                break;
            }
        }

        // Искусственное ограничение по условию задачи
        if (n == 9) {
            throw std::runtime_error("Нельзя вычислять 9-ое число Фибоначчи!");
        }

        // Обработка простых случаев
        if (n == 0) {
            std::cout << "Число Фибоначчи №0 равно 0\n";
            return ;
        }
        if (n == 1) {
            std::cout << "Число Фибоначчи №1 равно 1\n";
            return ;
        }

        // Количество потоков фиксировано = 4
        const unsigned threads_count = 4;

        // Переменные для вычисления чисел Фибоначчи
        long long a = 0, b = 1; // начальные значения F(0)=0, F(1)=1
        int step = 2;           // начинаем вычисление с F(2)
        bool done = false;      // флаг окончания

        // Мьютекс и условная переменная для синхронизации
        std::mutex m;
        std::condition_variable cv;
        unsigned turn = 0; // указывает, какой поток сейчас работает

        // Функция, выполняемая потоком
        auto worker = [&](unsigned id) {
            std::unique_lock<std::mutex> lk(m);
            while (!done) {

                // Ждём своей очереди
                cv.wait(lk, [&]{ return done || (turn == id && step <= n); });
                if (done || step > n) break;

                // Вычисляем очередное число Фибоначчи
                long long temp = a + b;
                a = b;
                b = temp;

                // Вывод отладочной информации
                std::cout << "Поток " << id
                          << " вычислил F(" << step << ") = " << b << '\n';

                ++step; // переходим к следующему шагу

                // Передаём очередь следующему потоку
                turn = (turn + 1) % threads_count;

                // Если дошли до конца то завершаем
                if (step > n) done = true;

                // Будим все потоки
                cv.notify_all();
            }
        };

        // Создаём массив потоков
        std::thread threads[threads_count];
        for (unsigned i = 0; i < threads_count; ++i) {
            threads[i] = std::thread(worker, i);
        }

        // Запускаем первый поток
        {
            std::lock_guard<std::mutex> lk(m);
            turn = 0;
        }
        cv.notify_all();

        // Дожидаемся завершения всех потоков
        for (unsigned i = 0; i < threads_count; ++i) {
            threads[i].join();
        }

        // Вывод результата
        std::cout << "Число Фибоначчи №" << n << " равно " << b << '\n';
    }
    catch (const std::exception &ex) {
        std::cout << "Исключение: " << ex.what() << '\n';
    }
}
