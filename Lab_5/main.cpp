/* Лабораторная работа №5
 * Группа №318
 * Developer: Хлуденцов П.В.
 * OS: Windows 10 Корпоративная
 * Locale (кодировка): IBM866
 */

#include <iostream>
#include <string>

enum Tasks {
    task_1 = 1,
    task_2,
    task_3,
    task_4,
    task_5,
    task_6,
    task_7,
    task_8
};

void in_int(const std::string & prompt, int & var); // Функция безопасного ввода целого числа
std::string in_string(const std::string& prompt); // Функция безопасного ввода строки
extern int main();
void Task_1(); // Задание №1
void Task_2(); // Задание №2
void Task_3(); // Задание №3
void Task_4(); // Задание №4
void Task_5(); // Задание №5
void Task_6(); // Задание №6
void Task_7(); // Задание №7
void Task_8(); // Задание №8

// Функция выполнения задания
void nymT(Tasks task) {
    switch (task) {
        case task_1:
            std::cout << "\nЗадание №1" << '\n';
            std::cout << '\n';
            Task_1();
            break;
        case task_2:
            std::cout << "\nЗадание №2" << '\n';
            std::cout << '\n';
            Task_2();
            break;
        case task_3:
            std::cout << "\nЗадание №3" << '\n';
            std::cout << '\n';
            Task_3();
            break;
        case task_4:
            std::cout << "\nЗадание №4" << '\n';
            std::cout << '\n';
            Task_4();
            break;
        case task_5:
            std::cout << "\nЗадание №5" << '\n';
            std::cout << '\n';
            Task_5();
            break;
        case task_6:
            std::cout << "\nЗадание №6" << '\n';
            std::cout << '\n';
            Task_6();
            break;
        case task_7:
            std::cout << "\nЗадание №7" << '\n';
            std::cout << '\n';
            Task_7();
            break;
        case task_8:
            std::cout << "\nЗадание №8" << '\n';
            std::cout << '\n';
            Task_8();
            break;         
    }
}

// Главная функция
int main() {    
    int n;
               std::cout << "Здравствуйте.\n";

      while (true) {
               in_int("\nВведите номер задания от 1-8: ", n);

               // Проверка на допустимый диапазон
               if (n < 1 || n > 8) {
                   std::cout << "Ошибка ввода.\n";
                   continue; // Запрашиваем номер задания снова
               }

               Tasks mytask = static_cast<Tasks>(n);
               nymT(mytask);               

               while (true) {                          
                           std::string bukv = in_string("\nХотите ли вы выйти из программы ? (y/n): ");

                           if (bukv == "y" || bukv == "Y") {
                               std::cout << "\nСпасибо за проверку! До свидания!\n";
                               return 0; // Выход из программы
                           } else if (bukv == "n" || bukv == "N") {
                               break; // Продолжаем цикл и запрашиваем задание снова
                           } else {
                               std::cout << "\nОтвет не распознан. Пожалуйста, введите 'y' или 'n': ";
                           }
                       }
}
 return 0;
}
