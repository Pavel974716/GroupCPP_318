#include <iostream>
#include <string>
#include <limits>

// Максимальное количество водителей, автомобилей и заявок на ремонт
const int MAX_DRIVERS = 10;
const int MAX_CARS = 10;
const int MAX_REPAIRS = 10;

// Класс автомобиля
class Car {
    std::string model;         // Модель автомобиля
    std::string licensePlate;  // Госномер
    bool needsRepair;          // Флаг: требуется ли ремонт

public:
    Car() : model(""), licensePlate(""), needsRepair(false) {}
    Car(std::string model, std::string licensePlate)
        : model(model), licensePlate(licensePlate), needsRepair(false) {}

    void markForRepair() { needsRepair = true; }   // Отметить как требующий ремонта
    void repair() { needsRepair = false; }         // Отремонтировать автомобиль

    bool isAvailable() const { return !needsRepair; } // Проверка доступности автомобиля

    void showStatus() const {
        std::cout << "Автомобиль [" << model << " гос№ " << licensePlate << "] - "
                  << (needsRepair ? "Требуется ремонт" : "Исправен") << '\n';
    }
};

// Объявление классов, которые будут использоваться далее
class Driver;
class TripRequest;
class RepairRequest;
class Dispatcher;

// Класс запроса на рейс
class TripRequest {
    std::string destination;   // Пункт назначения
    Driver* driver;            // Назначенный водитель
    Car* car;                  // Назначенный автомобиль
    bool completed;            // Флаг завершения рейса

public:
    TripRequest(std::string destination)
        : destination(destination), driver(nullptr), car(nullptr), completed(false) {}

    void assign(Driver* d, Car* c);        // Назначить водителя и авто
    void markCompleted(bool carOk);       // Отметить завершение рейса
};

// Класс водителя
class Driver {
    std::string name;      // Имя
    bool active;           // Активен или отстранён
    Car* assignedCar;      // Назначенный автомобиль
    bool onTrip;           // Флаг: находится ли в рейсе

public:
    Driver() : name(""), active(false), assignedCar(nullptr), onTrip(false) {}
    Driver(std::string name) : name(name), active(true), assignedCar(nullptr), onTrip(false) {}

    void assignCar(Car* car);                 // Назначение автомобиля водителю
    void requestRepair(Dispatcher& dispatcher);  // Запрос на ремонт
    void completeTrip(bool carOk);           // Завершение рейса
    void suspend();                          // Отстранение водителя

    bool isActive() const { return active; }
    Car* getCar() const { return assignedCar; }
    std::string getName() const { return name; }
    bool isOnTrip() const { return onTrip; }

    void endTrip();  // Завершение рейса (сброс флагов)
};

// Назначение рейса
void TripRequest::assign(Driver* d, Car* c) {
    driver = d;
    car = c;
    std::cout << "Рейс до пункта \"" << destination << "\" назначен водителю " << d->getName() << ".\n";
}

// Завершение рейса
void TripRequest::markCompleted(bool carOk) {
    completed = true;
    std::cout << "Рейс до \"" << destination << "\" завершён водителем " << driver->getName() << ".\n";
    if (!carOk && car != nullptr) {
        car->markForRepair();  // Отметить машину как неисправную
    }
}

// Класс заявки на ремонт
class RepairRequest {
    Driver* driver;   // Водитель, подавший заявку
    Car* car;         // Автомобиль, требующий ремонта

public:
    RepairRequest() : driver(nullptr), car(nullptr) {}
    RepairRequest(Driver* d, Car* c) : driver(d), car(c) {}

    void processRepair() {
        if (car) {
            std::cout << "Ремонт автомобиля для водителя " << driver->getName() << "...\n";
            car->repair();  // Выполнить ремонт
        }
    }
};

// Основной управляющий класс
class Dispatcher {
    Driver* drivers[MAX_DRIVERS];    // Массив указателей на водителей
    Car* cars[MAX_CARS];             // Массив указателей на автомобили
    RepairRequest repairs[MAX_REPAIRS]; // Массив заявок на ремонт
    int driverCount = 0;
    int carCount = 0;
    int repairCount = 0;

public:
    void addDriver(Driver* d);             // Добавить водителя
    void addCar(Car* c);                   // Добавить автомобиль
    void listDrivers();                    // Показать всех водителей
    void listCars();                       // Показать все машины
    void assignTrip(TripRequest& trip);    // Назначить рейс
    void receiveRepairRequest(Driver* d, Car* c); // Получить заявку на ремонт
    void suspendDriver(int index);         // Отстранить водителя
    void processRepairs();                 // Выполнить ремонт
    Driver* getDriver(int index);          // Получить водителя по индексу
};

// Назначение автомобиля водителю
void Driver::assignCar(Car* car) {
    if (car->isAvailable()) {
        assignedCar = car;
        onTrip = true;
        std::cout << "Водителю " << name << " назначен автомобиль.\n";
    } else {
        std::cout << "Автомобиль недоступен.\n";
    }
}

// Заявка на ремонт
void Driver::requestRepair(Dispatcher& dispatcher) {
    if (assignedCar) {
        assignedCar->markForRepair();  // Отметить машину
        dispatcher.receiveRepairRequest(this, assignedCar);
    } else {
        std::cout << "У водителя нет назначенного автомобиля.\n";
    }
}

// Завершение рейса
void Driver::completeTrip(bool carOk) {
    if (!assignedCar) {
        std::cout << "Нет назначенного автомобиля.\n";
        return;
    }
    if (!onTrip) {
        std::cout << "Водитель не в рейсе, завершать нечего.\n";
        return;
    }
    std::cout << name << " завершил рейс. Состояние автомобиля: "
              << (carOk ? "исправен" : "требуется ремонт") << '\n';
    if (!carOk) {
        assignedCar->markForRepair();
    }
    endTrip();  // Завершить рейс
}

// Сброс состояния после рейса
void Driver::endTrip() {
    onTrip = false;
    assignedCar = nullptr;
}

// Отстранение водителя
void Driver::suspend() {
    active = false;
    std::cout << "Водитель " << name << " отстранён от работы.\n";
}

// Реализация методов диспетчера
void Dispatcher::addDriver(Driver* d) {
    if (driverCount < MAX_DRIVERS) {
        drivers[driverCount++] = d;
    }
}

void Dispatcher::addCar(Car* c) {
    if (carCount < MAX_CARS) {
        cars[carCount++] = c;
    }
}

// Список водителей
void Dispatcher::listDrivers() {
    std::cout << "\nСписок водителей:\n";
    for (int i = 0; i < driverCount; ++i) {
        std::cout << i << ") " << drivers[i]->getName()
                  << (drivers[i]->isActive() ? " (Активен)" : " (Отстранён)")
                  << (drivers[i]->isOnTrip() ? " [В рейсе]" : "") << '\n';
    }
}

// Список автомобилей
void Dispatcher::listCars() {
    std::cout << "\nСписок автомобилей:\n";
    for (int i = 0; i < carCount; ++i) {
        std::cout << i << ") ";
        cars[i]->showStatus();
    }
}

// Назначение рейса
void Dispatcher::assignTrip(TripRequest& trip) {
    if (driverCount == 0 || carCount == 0) {
        std::cout << "Нет водителей или автомобилей для назначения рейса.\n";
        return;
    }
    for (int i = 0; i < driverCount; ++i) {
        if (drivers[i]->isActive() && !drivers[i]->isOnTrip()) {
            for (int j = 0; j < carCount; ++j) {
                if (cars[j]->isAvailable()) {
                    drivers[i]->assignCar(cars[j]);
                    trip.assign(drivers[i], cars[j]);
                    return;
                }
            }
        }
    }
    std::cout << "Нет доступных водителей или автомобилей для рейса.\n";
}

// Получение заявки на ремонт
void Dispatcher::receiveRepairRequest(Driver* d, Car* c) {
    if (repairCount < MAX_REPAIRS) {
        repairs[repairCount++] = RepairRequest(d, c);
        std::cout << "Заявка на ремонт автомобиля от водителя " << d->getName() << " принята.\n";
    }
}

// Отстранение водителя
void Dispatcher::suspendDriver(int index) {
    if (index >= 0 && index < driverCount) {
        drivers[index]->suspend();
    } else {
        std::cout << "Некорректный номер водителя.\n";
    }
}

// Обработка всех заявок на ремонт
void Dispatcher::processRepairs() {
    if (repairCount == 0) {
        std::cout << "Нет заявок на ремонт.\n";
        return;
    }
    for (int i = 0; i < repairCount; ++i) {
        repairs[i].processRepair();
    }
    repairCount = 0;
}

// Получение водителя по индексу
Driver* Dispatcher::getDriver(int index) {
    if (index >= 0 && index < driverCount) return drivers[index];
    return nullptr;
}

// Безопасный ввод числа
int getIntInput(std::string prompt, int min, int max) {
    int choice;
    while (true) {
        std::cout << prompt;
        std::cin >> choice;

        if (std::cin.fail() || choice < min || choice > max) {
            std::cout << "Ошибка ввода. Попробуйте снова.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

// Главная функция Task_3
void Task_3() {
    Dispatcher dispatcher;

    int choice;
    while (true) {
        std::cout << "\n--- МЕНЮ ---\n";
        std::cout << "1. Добавить водителя\n";
        std::cout << "2. Добавить автомобиль\n";
        std::cout << "3. Назначить рейс\n";
        std::cout << "4. Завершить рейс\n";
        std::cout << "5. Заявка на ремонт\n";
        std::cout << "6. Обработать ремонты\n";
        std::cout << "7. Отстранить водителя\n";
        std::cout << "8. Показать список водителей и машин\n";
        std::cout << "0. Выход\n";

        choice = getIntInput("\nВыберите пункт: ", 0, 8);

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::string name;
                std::cout << "Введите имя водителя: ";
                std::getline(std::cin, name);
                dispatcher.addDriver(new Driver(name));
                break;
            }
            case 2: {
                if (dispatcher.getDriver(0) == nullptr) {
                    std::cout << "Нет водителей. Сначала добавьте водителя.\n";
                    break;
                }
                std::string model, plate;
                std::cout << "Введите модель автомобиля: ";
                std::getline(std::cin, model);
                std::cout << "Введите госномер: ";
                std::getline(std::cin, plate);
                dispatcher.addCar(new Car(model, plate));
                break;
            }
            case 3: {
                std::string dest;
                std::cout << "Введите пункт назначения: ";
                std::getline(std::cin, dest);
                TripRequest trip(dest);
                dispatcher.assignTrip(trip);
                break;
            }
            case 4: {
                dispatcher.listDrivers();
                int idx = getIntInput("Введите номер водителя: ", 0, MAX_DRIVERS - 1);
                Driver* d = dispatcher.getDriver(idx);
                if (d && d->isOnTrip()) {
                    int status = getIntInput("Автомобиль после рейса исправен? (1 ? да, 0 ? нет): ", 0, 1);
                    d->completeTrip(status == 1);
                } else {
                    std::cout << "Неверный выбор или водитель не в рейсе.\n";
                }
                break;
            }
            case 5: {
                dispatcher.listDrivers();
                int idx = getIntInput("Введите номер водителя: ", 0, MAX_DRIVERS - 1);
                Driver* d = dispatcher.getDriver(idx);
                if (d) {
                    d->requestRepair(dispatcher);
                } else {
                    std::cout << "Неверный выбор.\n";
                }
                break;
            }
            case 6:
                dispatcher.processRepairs();
                break;
            case 7: {
                dispatcher.listDrivers();
                int idx = getIntInput("Введите номер водителя для отстранения: ", 0, MAX_DRIVERS - 1);
                dispatcher.suspendDriver(idx);
                break;
            }
            case 8:
                dispatcher.listDrivers();
                dispatcher.listCars();
                break;
        }
    }

    std::cout << "Выход из программы.\n";
}
