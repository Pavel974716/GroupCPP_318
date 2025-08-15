#include <iostream>
#include <string>
#include <limits>
#include <new> // ��� std::nothrow

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�
void in_int(const std::string & prompt, int & var); // �㭪�� ������᭮�� ����� 楫��� �᫠

// ��������
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

    // ��������� - ���� ������
    Creature() {
        name = in_string("\n������ �������� ������ ���� ����⢠: ");

        in_int("������ ������⢮ �����: ", head.count);
        if (head.count > 0) {
            head.types = new(std::nothrow) std::string[head.count];
            if (head.types == nullptr) {
                std::cerr << "�訡�� �뤥����� ����� ��� ⨯�� �����!\n";
                head.count = 0;
            } else {
                for (int i = 0; i < head.count; ++i) {
                    head.types[i] = in_string("������ ⨯ ������ #" + std::to_string(i + 1) + ": ");
                }
            }
        }

        in_int("������ ������⢮ ���: ", legs.count);

        cover.description = in_string("������ ���ᠭ�� ���஢� ⥫�: ");

        tail.type = in_string("������ ⨯ 墮��: ");

        in_int("������ ������⢮ ����: ", eyes.count);
        if (eyes.count > 0) {
            eyes.types = new(std::nothrow) std::string[eyes.count];
            if (eyes.types == nullptr) {
                std::cerr << "�訡�� �뤥����� ����� ��� ⨯�� ����!\n";
                eyes.count = 0;
            } else {
                for (int i = 0; i < eyes.count; ++i) {
                    eyes.types[i] = in_string("������ ⨯ ����� #" + std::to_string(i + 1) + ": ");
                }
            }
        }
    }

    // �������� - �᢮�������� �����
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

    // ��⮤ ��� �뢮�� ���ଠ樨
    void display() const {
        std::cout << "\n=== �������� ��� ===\n";
        std::cout << "��������: " << name << '\n';

        std::cout << "������ (" << head.count << "): ";
        if (head.count > 0 && head.types != nullptr) {
            for (int i = 0; i < head.count; ++i)
                std::cout << head.types[i] << "; ";
        } else {
            std::cout << "����������";
        }
        std::cout << '\n';

        std::cout << "����: " << legs.count << '\n';
        std::cout << "���஢ ⥫�: " << cover.description << '\n';
        std::cout << "�����: " << tail.type << '\n';

        std::cout << "����� (" << eyes.count << "): ";
        if (eyes.count > 0 && eyes.types != nullptr) {
            for (int i = 0; i < eyes.count; ++i)
                std::cout << eyes.types[i] << "; ";
        } else {
            std::cout << "����������";
        }
        std::cout << '\n';
    }
};

// ������� �㭪�� Task_2
void Task_2() {
    std::cout << "���� ����������! ��� ���� ᮧ��⥫�� ������ ����.\n";

    Creature* pCreature = nullptr;

    while (true) {
        std::string answer = in_string("\n���� ᮧ���� ����� ����⢮? (y/n): ");

        if (answer == "y" || answer == "Y") {
            pCreature = new(std::nothrow) Creature();
            if (pCreature == nullptr) {
                std::cerr << "�� 㤠���� �뤥���� ������ ��� ᮧ����� ����⢠!\n";
                continue;
            }

            std::cout << "\n�������� �����襭�!\n";
            pCreature->display();

            delete pCreature;
            pCreature = nullptr;

        } else if (answer == "n" || answer == "N") {
            break;
        } else {
            std::cout << "�⢥� �� �ᯮ����. ��������, ������ 'y' ��� 'n': \n";
        }
    }
}
