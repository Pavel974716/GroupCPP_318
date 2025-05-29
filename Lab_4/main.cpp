/* Лабораторная работа №4
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
    task_8,
    task_9
};

void in_int(const std::string & prompt, int & var); // Проверка ввода int
void Task_1(); // Задание №1
void Task_2a(); // Задание №2a
void Task_2b(); // Задание №2b
void Task_3(); // Задание №3
void Task_4a(); // Задание №4a
void Task_4b(); // Задание №4b
void Task_4c(); // Задание №4с
void Task_5(); // Задание №5
void Task_6a(); // Задание №6a
void Task_6b(); // Задание №6b
void Task_7(); // Задание №7
void Task_8(); // Задание №8
void Task_9(); // Задание №9

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
            std::cout << "\na) Матрица 5х5\n";
                   Task_2a();
            std::cout << "\nb) Mатрица 8х8\n";
                   Task_2b();
            break;
        case task_3:
            std::cout << "\nЗадание №3" << '\n';
            std::cout << '\n';
            Task_3();            
            break;
        case task_4:
            std::cout << "\nЗадание №4" << '\n';
            std::cout << '\n';
            Task_4a();
            Task_4b();
            Task_4c();
            break;
        case task_5:
            std::cout << "\nЗадание №5" << '\n';
            std::cout << '\n';
            Task_5();
            break;
        case task_6:
            std::cout << "\nЗадание №6" << '\n';
            std::cout << '\n';
            Task_6a();
            Task_6b();
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
         case task_9:
             std::cout << "\nЗадание №9" << '\n';
             std::cout << '\n';
             Task_9();
          break;          
    }
}

// Главная функция
int main() {
    int n;
               std::cout << "Здравствуйте.\n";

      while (true) {
               in_int("\nВведите номер задания от 1-9: ", n);

               // Проверка на допустимый диапазон
               if (n < 1 || n > 9) {
                   std::cout << "Ошибка ввода.\n";
                   continue; // Запрашиваем номер задания снова
               }

               Tasks mytask = static_cast<Tasks>(n);
               nymT(mytask);
               std::cout << "\nХотите ли вы выйти из программы ? (y/n): ";
               std::string bukv; // Строка для хранения ответа пользователя

               while (true) {
                           std::cin >> bukv;

                           if (bukv == "y") {
                               std::cout << "\nСпасибо за проверку! До свидания!\n";
                               return 0; // Выход из программы
                           } else if (bukv == "n") {
                               break; // Продолжаем цикл и запрашиваем задание снова
                           } else {
                               std::cout << "\nОтвет не распознан. Пожалуйста, введите 'y' или 'n': ";
                           }
                       }
}
 return 0;
}
