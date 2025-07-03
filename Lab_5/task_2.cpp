#include <iostream>
#include <string>
#include <limits> // ��� std::numeric_limits
#include <cstdlib>  // ��� rand() � srand()
#include <ctime>    // ��� time()

std::string in_string(const std::string & prompt); // �㭪�� ������᭮�� ����� ��ப�
void in_int(const std::string & prompt, int & var); // �㭪�� ������᭮�� ����� 楫��� �᫠

// �������� ��� ���ᠭ�� ����⢠ � �������᪨�� ���ᨢ���
struct Head {
    int count;
    std::string *types; // �������᪨� ���ᨢ ��ப
};

struct Eyes {
    int count;
    std::string *types; // �������᪨� ���ᨢ ��ப
};

struct Legs {
    int count;
};

struct Cover {
    std::string description;
};

struct Tail {
    std::string type;
};

struct Creature {
    std::string name; // �������� ����
    Head head;
    Legs legs;
    Cover cover;
    Tail tail;
    Eyes eyes;

    // ��������� �� 㬮�砭��
    Creature() : head{0, nullptr}, eyes{0, nullptr} {}

    // �������� ��� �᢮�������� �����
    ~Creature() {
        delete[] head.types;
        delete[] eyes.types;
    }
};

// �������� ������ ����⢠ � ��⮬ ������⢠ ⨯��
Creature createCreature() {
    Creature creature;

    // ���� �������� ����
    creature.name = in_string("\n������ �������� ������ ���� ����⢠: ");

    // ���� ������⢠ �����
    int headCount;
    in_int("������ ������⢮ �����: ", headCount);
    creature.head.count = headCount;

    // �뤥����� ����� ��� ⨯� �����
    if (headCount > 0) {
        creature.head.types = new std::string[headCount];
        for (int i = 0; i < headCount; ++i) {
            creature.head.types[i] = in_string("������ ⨯ ������ #" + std::to_string(i + 1) + ": ");
        }
    } else {
        creature.head.types = nullptr; // �᫨ ����� ���
    }

    // ���� ������⢠ ���
    in_int("������ ������⢮ ���: ", creature.legs.count);

    // ���ᠭ�� ���஢� ⥫�
    creature.cover.description = in_string("������ ���ᠭ�� ���஢� ⥫�: ");

    // ��� 墮��
    creature.tail.type = in_string("������ ⨯ 墮��: ");

    // ���� ������⢠ ����
    int eyesCount;
    in_int("������ ������⢮ ����: ", eyesCount);
    creature.eyes.count = eyesCount;

    // �뤥����� ����� ��� ⨯� ����
    if (eyesCount > 0) {
        creature.eyes.types = new std::string[eyesCount];
        for (int i = 0; i < eyesCount; ++i) {
            creature.eyes.types[i] = in_string("������ ⨯ ����� #" + std::to_string(i + 1) + ": ");
        }
    } else {
        creature.eyes.types = nullptr; // �᫨ ���� ���
    }

    return creature;
}

// �㭪�� ��� �⮡ࠦ���� ���ଠ樨 � ����⢥
void displayCreature(const Creature& c) {
    std::cout << "\n=== �������� ��� ===\n";

    std::cout << "��������: " << c.name << '\n';

    std::cout << "������ (" << c.head.count << "): ";
    for (int i = 0; i < c.head.count; ++i) {
        std::cout << c.head.types[i] << "; ";
   }
   if (c.head.count == 0) {
       std::cout << "����������";
   }
   std::cout << '\n';

   std::cout << "����: " << c.legs.count << '\n';
   std::cout << "���஢ ⥫�: " << c.cover.description << '\n';
   std::cout << "�����: " << c.tail.type << '\n';

   std::cout << "����� (" << c.eyes.count << ") ⨯��: ";
   for (int i = 0; i < c.eyes.count; ++i) {
       std::cout << c.eyes.types[i] << "; ";
   }
   if (c.eyes.count == 0) {
       std::cout << "����������";
   }
   std::cout << '\n';
}

// ������� �㭪�� Task_2
void Task_2() {

     // ���樠������ ������� ��砩��� �ᥫ
     std::srand(std::time(nullptr));
     std::cout<<"���� ����������! ��� ���� ᮧ��⥫�� ������ ����.\n";

     while (true) {
         std::string bukv = in_string("\n���� ᮧ���� ����� ����⢮? (y/n): ");

         if (bukv == "y" || bukv == "Y") {
             Creature newCreature= createCreature();
             std::cout<<"\n�������� �����襭�!\n";
             displayCreature(newCreature);

             // ������ ��� newCreature ��⮬���᪨ �᢮��������� �� ��室� �� �㭪樨, ⠪ ��� �������� �맮�����.
             } else if (bukv == "n" || bukv == "N") {
             break;
         } else {
             std::cout << "�⢥� �� �ᯮ����. ��������, ������ 'y' ��� 'n': \n";
         }
     }
}
