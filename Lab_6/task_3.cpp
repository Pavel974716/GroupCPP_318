#include <iostream>
#include <string>
#include <limits>

// ���ᨬ��쭮� ������⢮ ����⥫��, ��⮬������ � ��� �� ६���
const int MAX_DRIVERS = 10;
const int MAX_CARS = 10;
const int MAX_REPAIRS = 10;

// ����� ��⮬�����
class Car {
    std::string model;         // ������ ��⮬�����
    std::string licensePlate;  // ��᭮���
    bool needsRepair;          // ����: �ॡ���� �� ६���

public:
    Car() : model(""), licensePlate(""), needsRepair(false) {}
    Car(std::string model, std::string licensePlate)
        : model(model), licensePlate(licensePlate), needsRepair(false) {}

    void markForRepair() { needsRepair = true; }   // �⬥��� ��� �ॡ��騩 ६���
    void repair() { needsRepair = false; }         // ��६���஢��� ��⮬�����

    bool isAvailable() const { return !needsRepair; } // �஢�ઠ ����㯭��� ��⮬�����

    void showStatus() const {
        std::cout << "��⮬����� [" << model << " ���� " << licensePlate << "] - "
                  << (needsRepair ? "�ॡ���� ६���" : "��ࠢ��") << '\n';
    }
};

// ������� ����ᮢ, ����� ���� �ᯮ�짮������ �����
class Driver;
class TripRequest;
class RepairRequest;
class Dispatcher;

// ����� ����� �� ३�
class TripRequest {
    std::string destination;   // �㭪� �����祭��
    Driver* driver;            // �����祭�� ����⥫�
    Car* car;                  // �����祭�� ��⮬�����
    bool completed;            // ���� �����襭�� ३�

public:
    TripRequest(std::string destination)
        : destination(destination), driver(nullptr), car(nullptr), completed(false) {}

    void assign(Driver* d, Car* c);        // �������� ����⥫� � ���
    void markCompleted(bool carOk);       // �⬥��� �����襭�� ३�
};

// ����� ����⥫�
class Driver {
    std::string name;      // ���
    bool active;           // ��⨢�� ��� ����࠭�
    Car* assignedCar;      // �����祭�� ��⮬�����
    bool onTrip;           // ����: ��室���� �� � ३�

public:
    Driver() : name(""), active(false), assignedCar(nullptr), onTrip(false) {}
    Driver(std::string name) : name(name), active(true), assignedCar(nullptr), onTrip(false) {}

    void assignCar(Car* car);                 // �����祭�� ��⮬����� ����⥫�
    void requestRepair(Dispatcher& dispatcher);  // ����� �� ६���
    void completeTrip(bool carOk);           // �����襭�� ३�
    void suspend();                          // ����࠭���� ����⥫�

    bool isActive() const { return active; }
    Car* getCar() const { return assignedCar; }
    std::string getName() const { return name; }
    bool isOnTrip() const { return onTrip; }

    void endTrip();  // �����襭�� ३� (��� 䫠���)
};

// �����祭�� ३�
void TripRequest::assign(Driver* d, Car* c) {
    driver = d;
    car = c;
    std::cout << "���� �� �㭪� \"" << destination << "\" �����祭 ����⥫� " << d->getName() << ".\n";
}

// �����襭�� ३�
void TripRequest::markCompleted(bool carOk) {
    completed = true;
    std::cout << "���� �� \"" << destination << "\" ������� ����⥫�� " << driver->getName() << ".\n";
    if (!carOk && car != nullptr) {
        car->markForRepair();  // �⬥��� ��設� ��� ����ࠢ���
    }
}

// ����� ��� �� ६���
class RepairRequest {
    Driver* driver;   // ����⥫�, �����訩 ���
    Car* car;         // ��⮬�����, �ॡ��騩 ६���

public:
    RepairRequest() : driver(nullptr), car(nullptr) {}
    RepairRequest(Driver* d, Car* c) : driver(d), car(c) {}

    void processRepair() {
        if (car) {
            std::cout << "������ ��⮬����� ��� ����⥫� " << driver->getName() << "...\n";
            car->repair();  // �믮����� ६���
        }
    }
};

// �᭮���� �ࠢ���騩 �����
class Dispatcher {
    Driver* drivers[MAX_DRIVERS];    // ���ᨢ 㪠��⥫�� �� ����⥫��
    Car* cars[MAX_CARS];             // ���ᨢ 㪠��⥫�� �� ��⮬�����
    RepairRequest repairs[MAX_REPAIRS]; // ���ᨢ ��� �� ६���
    int driverCount = 0;
    int carCount = 0;
    int repairCount = 0;

public:
    void addDriver(Driver* d);             // �������� ����⥫�
    void addCar(Car* c);                   // �������� ��⮬�����
    void listDrivers();                    // �������� ��� ����⥫��
    void listCars();                       // �������� �� ��設�
    void assignTrip(TripRequest& trip);    // �������� ३�
    void receiveRepairRequest(Driver* d, Car* c); // ������� ��� �� ६���
    void suspendDriver(int index);         // ����࠭��� ����⥫�
    void processRepairs();                 // �믮����� ६���
    Driver* getDriver(int index);          // ������� ����⥫� �� �������
};

// �����祭�� ��⮬����� ����⥫�
void Driver::assignCar(Car* car) {
    if (car->isAvailable()) {
        assignedCar = car;
        onTrip = true;
        std::cout << "����⥫� " << name << " �����祭 ��⮬�����.\n";
    } else {
        std::cout << "��⮬����� ������㯥�.\n";
    }
}

// ��� �� ६���
void Driver::requestRepair(Dispatcher& dispatcher) {
    if (assignedCar) {
        assignedCar->markForRepair();  // �⬥��� ��設�
        dispatcher.receiveRepairRequest(this, assignedCar);
    } else {
        std::cout << "� ����⥫� ��� �����祭���� ��⮬�����.\n";
    }
}

// �����襭�� ३�
void Driver::completeTrip(bool carOk) {
    if (!assignedCar) {
        std::cout << "��� �����祭���� ��⮬�����.\n";
        return;
    }
    if (!onTrip) {
        std::cout << "����⥫� �� � ३�, �������� ��祣�.\n";
        return;
    }
    std::cout << name << " �����訫 ३�. ����ﭨ� ��⮬�����: "
              << (carOk ? "��ࠢ��" : "�ॡ���� ६���") << '\n';
    if (!carOk) {
        assignedCar->markForRepair();
    }
    endTrip();  // �������� ३�
}

// ���� ���ﭨ� ��᫥ ३�
void Driver::endTrip() {
    onTrip = false;
    assignedCar = nullptr;
}

// ����࠭���� ����⥫�
void Driver::suspend() {
    active = false;
    std::cout << "����⥫� " << name << " ����࠭� �� ࠡ���.\n";
}

// ��������� ��⮤�� ��ᯥ���
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

// ���᮪ ����⥫��
void Dispatcher::listDrivers() {
    std::cout << "\n���᮪ ����⥫��:\n";
    for (int i = 0; i < driverCount; ++i) {
        std::cout << i << ") " << drivers[i]->getName()
                  << (drivers[i]->isActive() ? " (��⨢��)" : " (����࠭�)")
                  << (drivers[i]->isOnTrip() ? " [� ३�]" : "") << '\n';
    }
}

// ���᮪ ��⮬������
void Dispatcher::listCars() {
    std::cout << "\n���᮪ ��⮬������:\n";
    for (int i = 0; i < carCount; ++i) {
        std::cout << i << ") ";
        cars[i]->showStatus();
    }
}

// �����祭�� ३�
void Dispatcher::assignTrip(TripRequest& trip) {
    if (driverCount == 0 || carCount == 0) {
        std::cout << "��� ����⥫�� ��� ��⮬������ ��� �����祭�� ३�.\n";
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
    std::cout << "��� ����㯭�� ����⥫�� ��� ��⮬������ ��� ३�.\n";
}

// ����祭�� ��� �� ६���
void Dispatcher::receiveRepairRequest(Driver* d, Car* c) {
    if (repairCount < MAX_REPAIRS) {
        repairs[repairCount++] = RepairRequest(d, c);
        std::cout << "��� �� ६��� ��⮬����� �� ����⥫� " << d->getName() << " �ਭ��.\n";
    }
}

// ����࠭���� ����⥫�
void Dispatcher::suspendDriver(int index) {
    if (index >= 0 && index < driverCount) {
        drivers[index]->suspend();
    } else {
        std::cout << "�����४�� ����� ����⥫�.\n";
    }
}

// ��ࠡ�⪠ ��� ��� �� ६���
void Dispatcher::processRepairs() {
    if (repairCount == 0) {
        std::cout << "��� ��� �� ६���.\n";
        return;
    }
    for (int i = 0; i < repairCount; ++i) {
        repairs[i].processRepair();
    }
    repairCount = 0;
}

// ����祭�� ����⥫� �� �������
Driver* Dispatcher::getDriver(int index) {
    if (index >= 0 && index < driverCount) return drivers[index];
    return nullptr;
}

// �������� ���� �᫠
int getIntInput(std::string prompt, int min, int max) {
    int choice;
    while (true) {
        std::cout << prompt;
        std::cin >> choice;

        if (std::cin.fail() || choice < min || choice > max) {
            std::cout << "�訡�� �����. ���஡�� ᭮��.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

// ������� �㭪�� Task_3
void Task_3() {
    Dispatcher dispatcher;

    int choice;
    while (true) {
        std::cout << "\n--- ���� ---\n";
        std::cout << "1. �������� ����⥫�\n";
        std::cout << "2. �������� ��⮬�����\n";
        std::cout << "3. �������� ३�\n";
        std::cout << "4. �������� ३�\n";
        std::cout << "5. ��� �� ६���\n";
        std::cout << "6. ��ࠡ���� ६����\n";
        std::cout << "7. ����࠭��� ����⥫�\n";
        std::cout << "8. �������� ᯨ᮪ ����⥫�� � ��設\n";
        std::cout << "0. ��室\n";

        choice = getIntInput("\n�롥�� �㭪�: ", 0, 8);

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::string name;
                std::cout << "������ ��� ����⥫�: ";
                std::getline(std::cin, name);
                dispatcher.addDriver(new Driver(name));
                break;
            }
            case 2: {
                if (dispatcher.getDriver(0) == nullptr) {
                    std::cout << "��� ����⥫��. ���砫� ������� ����⥫�.\n";
                    break;
                }
                std::string model, plate;
                std::cout << "������ ������ ��⮬�����: ";
                std::getline(std::cin, model);
                std::cout << "������ ��᭮���: ";
                std::getline(std::cin, plate);
                dispatcher.addCar(new Car(model, plate));
                break;
            }
            case 3: {
                std::string dest;
                std::cout << "������ �㭪� �����祭��: ";
                std::getline(std::cin, dest);
                TripRequest trip(dest);
                dispatcher.assignTrip(trip);
                break;
            }
            case 4: {
                dispatcher.listDrivers();
                int idx = getIntInput("������ ����� ����⥫�: ", 0, MAX_DRIVERS - 1);
                Driver* d = dispatcher.getDriver(idx);
                if (d && d->isOnTrip()) {
                    int status = getIntInput("��⮬����� ��᫥ ३� ��ࠢ��? (1 ? ��, 0 ? ���): ", 0, 1);
                    d->completeTrip(status == 1);
                } else {
                    std::cout << "������ �롮� ��� ����⥫� �� � ३�.\n";
                }
                break;
            }
            case 5: {
                dispatcher.listDrivers();
                int idx = getIntInput("������ ����� ����⥫�: ", 0, MAX_DRIVERS - 1);
                Driver* d = dispatcher.getDriver(idx);
                if (d) {
                    d->requestRepair(dispatcher);
                } else {
                    std::cout << "������ �롮�.\n";
                }
                break;
            }
            case 6:
                dispatcher.processRepairs();
                break;
            case 7: {
                dispatcher.listDrivers();
                int idx = getIntInput("������ ����� ����⥫� ��� ����࠭����: ", 0, MAX_DRIVERS - 1);
                dispatcher.suspendDriver(idx);
                break;
            }
            case 8:
                dispatcher.listDrivers();
                dispatcher.listCars();
                break;
        }
    }

    std::cout << "��室 �� �ணࠬ��.\n";
}
