#include "ring_buffer.h"
#include <thread>
#include <chrono>
#include <atomic>
#include <limits>
#include <iostream>

// Главная функция Task_5
void Task_5() {
    try {

        // Здесь задаём размер (ёмкость) кольцевого буфера - 8 элементов
        RingBuffer rb(8);

        std::cout << "a) Проверка кольцевого буфера \n";
        std::cout << "Буфер создаётся на 8 элементов.\n"
                       << "Поток записывает возрастающие числа каждые 200 мс.\n"
                       << "После заполнения новые записи затирают старые (wrap-around).\n"
                       << "Для выхода введите 'q' и нажмите Enter.\n\n";

        // Подготовка фонового потока
        std::atomic<bool> running(true);       

        // Фоновый поток: регулярно добавляет значения в буфер
        std::thread writer([&]() {
            int x = 1;  // будем писать 1, 2, 3, ...
            while (running.load()) {
                rb + x;   // запись очередного значения
                ++x;

                // Выводим текущее состояние            
                std::cout << "\rБуфер: " << rb
                               << "   | head=" << rb.head_index()
                               << " size=" << rb.size()
                               << "  Введите команду... "
                               << std::flush;

                // Пауза 200 мс
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
        });

        while (true) {
            std::string input;
            if (!(std::cin >> input)) {                
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                
                continue;
            }            

            if (input.size() != 1) {
                std::cout << "Неверная команда. Введите одну букву.\n\n";
                continue;
            }

            char ch = input[0];
            if (ch == 'q' || ch == 'Q') {
                break;
            } else {
                std::cout << "Неизвестная команда. Для выхода введите 'q'.\n\n";
            }
        }
        std::cout << '\n';

        running.store(false);            // сообщаем потоку пора завершаться
        if (writer.joinable()) writer.join();  // дожидаемся завершения

        std::cout << "Итоговое состояние буфера\n";
        std::cout << rb << "\n\n";
        std::cout << "b) Вывод содержимого \n";
        std::cout << "Все элементы буфера:\n" << rb << '\n';

        // Вывод диапазона логических индексов [2..5]
        // Проверяем, что элементов достаточно (нужно минимум 6)
        if (rb.size() > 5) {
            std::cout << "Элементы с индекса 2 по 5:\n";
            rb.printRange(std::cout, 2, 5); // печатает элементы 2,3,4,5 (логические индексы)
            std::cout << '\n';
        } else {
            std::cout << "Недостаточно элементов для вывода диапазона [2..5] (size=" << rb.size() << ")\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nПрограмма завершена.\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << '\n';
    }
}


