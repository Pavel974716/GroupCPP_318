/* ������ୠ� ࠡ�� �3
 * ��㯯� �318
 * Developer: ��㤥�殢 �.�.
 * OS: Windows 10 ��௮�⨢���
 * Locale (����஢��): IBM866
 */


#include <iostream>
#include <iomanip> // ��� std::setprecision, ��࠭�祭�� �ᥫ ��᫥ ����⮩

// ��।������ ����᫥���
enum Animal {
    pig,
    chicken,
    goat,
    cat,
    dog
};

enum Floors {
    Parking,
    FoodCourt,
    Clothing,
    Electronics,
    Cinema,
    KidsZone,
    Entertainment,
    RooftopCafe
};

// �㭪�� ����� �������
int nomZad()
{
    std::cout << "������ ����� �������  ";
    int z;
    std::cin >> z;
    std::cout << '\n';
    return z;
}

// �㭪�� ������� 1
void task_1()
{
    // ������� 1�

    std::cout << "������� �1 \n";
    std::cout << '\n';
    // �ᥣ� ������⢠ ����
    const int total_cardc = 52;
    // ������⢮ �㧮�
    const int aces = 4;
    // ����⭮���
    double probability_kar = static_cast<double>(aces)/total_cardc;
    std::cout << "�) ";
    std::cout << "����⭮��� ������ �㧠 �� ������ � 52 ����� = " << probability_kar;
    std::cout << " � ��業�� " << std::setprecision(3) << probability_kar*100 << " % \n";
    std::cout << '\n';

    // ������� 1�

    // ��饥 ������⢮ ��室��
    const int total_quantity = 36;
    // ������⢮ ����������� ��室��
    const int favorable_quantity = 6;
    // ����⭮���
    double probability_kos = static_cast<double>(favorable_quantity)/total_quantity;
    std::cout << "B) ";
    std::cout << "����⭮��� ⮣�, �� �㬬� �믠��� �窮� �㤥� ࠢ�� 7 = " << probability_kos;
    std::cout << " � ��業�� " << std::setprecision(3) << probability_kos*100 << " % \n";
    std::cout << '\n';

    // ������� 1�

    // ��饥 ������⢮ ����⠭����
    const int total_quantityPer = 6; // 4! / (2! * 2!) = 6
    // ������⢮ ����������� ��室��
    const int favorable_outcomes = 1; // ⠪ ��� ⮫쪮 ���� ᫮��
    // ����⭮���
    double probability_buk = static_cast<double>(favorable_outcomes) / total_quantityPer;
    std::cout << "�) ";
    std::cout << "����⭮��� ⮣�, �� �� ��砩��� �ᯮ������� �㪢 �������� ᫮�� <<����>> = ";
    std::cout << probability_buk << " � ��業�� " <<  std::setprecision(3) << probability_buk*100 << " % \n";
    std::cout << '\n';
}

// �㭪�� ������� 2
void printChar(int a = 'a', char b = 'b', char c = 'c', char d = 'd')
{
    std::cout << "a: " << static_cast<char>(a) << ", b: " << b << ", c: " << c << ", d: " << d << '\n';
}

// ���⨯ �㭪�� ������� 3
int globalValue = 10; // ������쭠� ��६�����

// ���⨯ �㭪樨 � �ᯮ�짮������ trailing
auto initializeVariables() -> void;

// �㭪樨 ������� 4
    // �㭪��, �ਭ������ ��㬥�� ⨯� Animal
void getAnimalName(Animal animal) {
    switch (animal) {
        case pig:
            std::cout << "Animal: Pig" << '\n';
            break;
        case chicken:
            std::cout << "Animal: Chicken" << '\n';
            break;
        case goat:
            std::cout << "Animal: Goat" << '\n';
            break;
        case cat:
            std::cout << "Animal: Cat" << '\n';
            break;
        case dog:
            std::cout << "Animal: Dog" << '\n';
            break;
        default:
            std::cout << "Error: Unknown animal!" << '\n';
    }
}

void printNumberOfLegs(Animal animal) {
    switch (animal) {
        case pig:
            std::cout << "Number of legs: 4" << '\n';
            break;
        case chicken:
            std::cout << "Number of legs: 2" << '\n';
            break;
        case goat:
            std::cout << "Number of legs: 4" << '\n';
            break;
        case cat:
            std::cout << "Number of legs: 4" << '\n';
            break;
        case dog:
            std::cout << "Number of legs: 4" << '\n';
            break;
        default:
            std::cout << "Error: Unknown animal!" << '\n';
    }
}

// �㭪樨 ������� 5
// �㭪樨 ��� ���᪠ ���ᨬ㬠 � �����㬠 � ��ࠬ��ࠬ� ⨯� int
int findMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int findMin(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// ��ॣ�㧪� �㭪権 ��� ��ࠬ��஢ ⨯� unsigned short
unsigned short findMax(unsigned short a, unsigned short b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

unsigned short findMin(unsigned short a, unsigned short b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// ��ॣ�㧪� �㭪権 ��� ��� ��ࠬ��஢ ⨯� int
int findMax(int a, int b, int limit) {
    int maximum;
     // ��室�� ���ᨬ�
     if (a > b) {
          maximum = a;
      } else {
          maximum = b;
      }

     // �஢��塞, ����� �� ���ᨬ� �।���
     if (maximum > limit) {
          return maximum; // �᫨ �����, �����頥� ���ᨬ�
     } else {
          return limit; // ���� �����頥� �।��
     }
}

int findMin(int a, int b, int limit) {
    int minimum;
    // ��室�� ������
    if (a < b) {
         minimum = a;
    } else {
         minimum = b;
    }

    // �஢��塞, ���� �� ������ �।���
    if (minimum < limit) {
         return minimum; // �᫨ ����, �����頥� �।��
    } else {
         return limit; // ���� �����頥� �������� ������
    }
}

// �㭪�� ������� 6
void task_6()
{
    int x = 50;
    float y = 5.5f;
    double z = 3.3;
    unsigned short k =25;

    // ��ࠦ���� 1) int i = (x + y) * z + k;
            // (x + y) ? x (int) ��� �ਢ������ � float, १���� float.
            // (x + y) * z ? float * double ? ��� �ਢ������ � double.
            // (x + y) * z + k ? k (unsigned short) ��� �ਢ������ � double.
            // �⮣ ��ࠦ���� ? double, ��ᢠ������� � int i ? ���� �८�ࠧ������

    std::cout << "int x = 50;   float y = 5.5f;   double z = 3.3;   unsigned short k =25;" << '\n';
    std::cout << '\n';

    // � ��� �ਢ�������
    int i1 = (x + y) * z + k;  // double -> int (���)
    std::cout << "� ��� �ਢ������� " << '\n';
    std::cout << "int i = (x + y) * z + k; " << " double -> int; " << "    ������� ��ࠦ���� = " << i1 << '\n';
    // c � �ਢ�������
    int i2 = static_cast<int>( ((x + y) * z) + k );
    std::cout << "� � �ਢ������� " << '\n';
    std::cout << "int i = static_cast<int>( ((x + y) * z) + k ); " << "    ������� ��ࠦ���� = " << i2 << '\n';
    std::cout << '\n';

    // ��ࠦ���� 2) k = x - y / z;
            // y / z ? float / double ? float ��� �ਢ������ � double, १���� double.
            // x - (y / z) ? int - double ? int ��� �ਢ������ � double, १���� double.
            // ��ᢠ����� � k (unsigned short), �.�. �� double � unsigned short ? ���� �८�ࠧ������.

    // � ��� �ਢ�������
    k = x - y / z;  // double -> unsigned short (���)
    std::cout << "� ��� �ਢ������� " << '\n';
    std::cout << "k = x - y / z; " << "  double -> unsigned short; " << "    ������� ��ࠦ���� = " << k << '\n';
    // c � �ਢ�������
    k = static_cast<unsigned short>( x - y / z );
    std::cout << "� � �ਢ������� " << '\n';
    std::cout << "k = static_cast<unsigned short>( x - y / z ); " << "    ������� ��ࠦ���� = " << k << '\n';
    std::cout << '\n';

    // ��ࠦ���� 3) z = x * y + z / x;
            // x * y ? int * float ? int ��� � float, १���� float.
            // z / x ? double / int ? int ��� � double, १���� double.
            // c�������: float + double ? float ��� � double, १���� double.
            // ��ᢠ����� � z (double), ⨯ ᮢ������.

    // � ��� �ਢ�������
    z = x * y + z / x;  // double
    std::cout << "� ��� �ਢ������� " << '\n';
    std::cout << "z = x * y + z / x; " << "  double " << "    ������� ��ࠦ���� = " << z << '\n';
    // c � �ਢ�������
    z = static_cast<double>(static_cast<float>(x)*y) + static_cast<double>(z/x);
    std::cout << "� � �ਢ������� " << '\n';
    std::cout << "z = static_cast<double>(x * y) + z / x; " << "    ������� ��ࠦ���� = " << z << '\n';
    std::cout << '\n';

    // ��ࠦ���� 4) unsigned int ui = x / y + k;
            // x / y ? int / float ? int ��� � float, १���� float.
            // � float �ਡ���塞 k (unsigned short), ����� ��� �ਢ������ � float.
            // �⮣ ��ࠦ���� ? float.
            // ��ᢠ����� � unsigned int ? ���� �८�ࠧ������.

    // � ��� �ਢ�������
    unsigned int ui1 = x / y + k;  // float -> unsigned int (���)
    std::cout << "� ��� �ਢ������� " << '\n';
    std::cout << "unsigned int ui = x / y + k; " << " float -> unsigned int; " << "    ������� ��ࠦ���� = " << ui1 << '\n';
    // c � �ਢ�������
    unsigned int ui2 = static_cast<unsigned int>( x / y + k );
    std::cout << "� � �ਢ������� " << '\n';
    std::cout << "unsigned int ui = static_cast<unsigned int>( x / y + k ); " << "    ������� ��ࠦ���� = " << ui2 << '\n';
    std::cout << '\n';

    // ��ࠦ���� 5) short s = x % (x / y);
            // % ������ �ਬ������ ⮫쪮 � 楫��᫥��� ⨯��.
            // � ��ࠦ���� (x/y) ? ������� int �� float ? १���� �㤥� float.
            // ����� �ᯮ�짮���� % � ������饩 �窮�.
            // �⮡� ��ࠢ���, �㦭� � �ਢ��� (x/y) � 楫��� ⨯�.

    // c � �ਢ�������
    short s = x % static_cast<int>(x / y);
    std::cout << "� � �ਢ������� " << '\n';
    std::cout << "short s = x % static_cast<int>(x / y); " << "    ������� ��ࠦ���� = " << s << '\n';
    std::cout << '\n';
}

// �㭪�� ������� 7
void numF(Floors floors) {
    switch (floors) {
        case Parking:
            std::cout << "�� �ਥ堫� �� �⠦: ��મ���" << '\n';
            break;
        case FoodCourt:
            std::cout << "�� �ਥ堫� �� �⠦: �㤪���" << '\n';
            break;
        case Clothing:
            std::cout << "�� �ਥ堫� �� �⠦: �⤥� ������" << '\n';
            break;
        case Electronics:
            std::cout << "�� �ਥ堫� �� �⠦: �����஭���" << '\n';
            break;
        case Cinema:
            std::cout << "�� �ਥ堫� �� �⠦: ����⥠��" << '\n';
            break;
        case KidsZone:
            std::cout << "�� �ਥ堫� �� �⠦: ���᪠� ����" << '\n';
            break;
        case Entertainment:
            std::cout << "�� �ਥ堫� �� �⠦: ��������⥫�� 業��" << '\n';
            break;
        case RooftopCafe:
            std::cout << "�� �ਥ堫� �� �⠦: ��� �� ����" << '\n';
            break;
        default:
            std::cout << "�訡��: �⠦ ������ ���� �� 0 �� 7." << '\n';
    }
}

// ������� �㭪��
int main()
{
    zapros:
    int n=nomZad();
                        // ������� 1
                        if (n==1){
                            task_1();
                        // ������� 2
                        }
                        else if (n==2){
                            std::cout << "������� �2 \n";
                            std::cout << '\n';
                            printChar();                  // �맮� ��� ��㬥�⮢
                            printChar('x');              // �맮� � ����� ��㬥�⮬
                            printChar('x', 'y');         // �맮� � ���� ��㬥�⠬�
                            printChar('x', 'y', 'z');    // �맮� � �६� ��㬥�⠬�
                            printChar('w', 'x', 'y', 'z');// �맮� � �ᥬ� ������ ��㬥�⠬�
                            std::cout << '\n';
                        }
                        // ������� 3
                        else if (n==3){
                            std::cout << "������� �3 \n";
                            std::cout << '\n';
                            initializeVariables();
                             // �����쭠� ��६����� � ⥬ �� ������
                             int globalValue = 20; // �����쭠� ��६�����

                             std::cout << "������쭠� ��६�����: " << ::globalValue << '\n'; // �ᯮ��㥬 :: ��� ����㯠 � ������쭮� ��६�����
                             std::cout << "�����쭠� ��६�����: " << globalValue << '\n'; // �����쭠� ��६�����
                             std::cout << '\n';
                        }
                        //������� 4
                        else if (n==4){
                            std::cout << "������� �4 \n";
                            std::cout << '\n';
                            // ᮧ���� ��६����� ⨯� Animal � ��ᢠ����� �� ���祭��
                            Animal myAnimal = static_cast<Animal>(2);

                            // ��뢠�� �㭪樨 � ��㬥�⮬ myAnimal
                            getAnimalName(myAnimal);
                            printNumberOfLegs(myAnimal);
                            std::cout << '\n';
                        }
                        //������� 5
                        else if (n==5){
                            std::cout << "������� �5 \n";
                            std::cout << '\n';

                            int num1, num2;
                            std::cout << "������ ��� �᫠ (int): \n";
                            std::cin >> num1 >> num2;
                            // ���᫥��� ���ᨬ㬠 � �����㬠
                            int maxInt = findMax(num1, num2);
                            int minInt = findMin(num1, num2);
                            std::cout << "���ᨬ�: " << maxInt << '\n';
                            std::cout << "������: " << minInt << '\n';
                            std::cout << '\n';

                            unsigned short ushort1, ushort2;
                            std::cout << "������ ��� �᫠ (unsigned short): \n";
                            std::cin >> ushort1 >> ushort2;
                            // ���᫥��� ���ᨬ㬠 � �����㬠 ��� unsigned short
                            unsigned short maxUShort = findMax(ushort1, ushort2);
                            unsigned short minUShort = findMin(ushort1, ushort2);
                            std::cout << "���ᨬ� (unsigned short): " << maxUShort << '\n';
                            std::cout << "������ (unsigned short): " << minUShort << '\n';
                            std::cout << '\n';

                            // ���� ��� �ᥫ ��� ��࠭�祭��
                            int limitMax, limitMin, num3;

                            std::cout << "������ �� �᫠ ( max, min � ��ண ��࠭�祭��): \n";
                            std::cin >> limitMax >> limitMin >> num3;
                            // ���᫥��� ���ᨬ㬠 � �����㬠 � ��⮬ ��ண� ��࠭�祭��
                            int constrainedMax = findMax(limitMax, limitMin, num3);
                            int constrainedMin = findMin(limitMax, limitMin, num3);
                            std::cout << "���ᨬ� � ��⮬ ��ண�: " << constrainedMax << '\n';
                            std::cout << "������ � ��⮬ ��ண�: " << constrainedMin << '\n';
                            std::cout << '\n';
                        }
                        //������� 6
                        else if (n==6){
                            std::cout << "������� �6 \n";
                            std::cout << '\n';
                            task_6();
                        }
                        //������� 7
                        else if (n==7){
                            std::cout << "������� �7 \n";
                            std::cout << '\n';
                            std::cout << "���� ���������� � ����㠫�� �࣮��-ࠧ�����⥫�� 業��!\n";


                            floor:
                            std::cout << "\n������ �⠦ (0-7), �㤠 ��� ������:\n";
                            std::cout << "0 - ��મ��� \n";
                            std::cout << "1 - �㤪��� \n";
                            std::cout << "2 - �⤥� ������ \n";
                            std::cout << "3 - �����஭��� \n";
                            std::cout << "4 - ����⥠�� \n";
                            std::cout << "5 - ���᪠� ���� \n";
                            std::cout << "6 - ��������⥫�� 業�� \n";
                            std::cout << "7 - ��� �� ���� \n";
                            std::cout << '\n';

                            int floorInput;
                            std::cin >> floorInput;
                            std::cout << '\n';

                            Floors myFloors = static_cast<Floors>(floorInput);
                                numF(myFloors);
                                // ���訢��� ���짮��⥫� � ��室� �� 業��
                            std::cout << "\n���� �� �� ��� �� �࣮���� 業��? (��/���): ";

                            std::string bukv; // ��ப� ��� �࠭���� �⢥� ���짮��⥫�
                            std::cin >> bukv;


                                if (bukv == "��") {
                                    std::cout << "\n���ᨡ� �� ���饭��! �� ᢨ�����!\n";
                                    std::cout << '\n';
                                } else if (bukv == "���") {
                                    goto floor; // �த������ 横� ��� ᫥���饩 �������
                                } else {
                                    std::cout << "�⢥� �� �ᯮ����. �த������ �������.\n";
                                    std::cout << '\n';
                                    goto floor; // �த������ 横� ��� ᫥���饩 �������
                                }
                        }
                        else {
                          std::cout << "������� � ⠪�� ����஬ ��� \n";
                          std::cout << '\n';
                        }
goto zapros;

return 0;
}

// ��।������ �㭪樨 ������� 3
void initializeVariables() {
    // ��������� ���樠������
    int iValue = 5;          // ��������� ���樠������
    bool cValue = true;     // ��������� ���樠������
    char charValue = 'A';   // ��������� ���樠������
    long lValue = 100000L;   // ��������� ���樠������

    std::cout << "Copy Initialization:" << '\n';
    std::cout << "iValue: " << iValue << '\n';
    std::cout << "cValue: " << cValue << '\n';
    std::cout << "charValue: " << charValue << '\n';
    std::cout << "lValue: " << lValue << '\n';
    std::cout << '\n';

    // ��ﬠ� ���樠������
    int iDirectInit(10);          // ��ﬠ� ���樠������
    bool cDirectInit(false);      // ��ﬠ� ���樠������
    char charDirectInit('B');     // ��ﬠ� ���樠������
    long lDirectInit(200000L);     // ��ﬠ� ���樠������

    std::cout << "Direct Initialization:" << '\n';
    std::cout << "iDirectInit: " << iDirectInit << '\n';
    std::cout << "cDirectInit: " << cDirectInit << '\n';
    std::cout << "charDirectInit: " << charDirectInit << '\n';
    std::cout << "lDirectInit: " << lDirectInit << '\n';
    std::cout << '\n';

    // �����஢����� ���樠������
    int iUniformInit{15};          // �����஢����� ���樠������
    bool cUniformInit{true};       // �����஢����� ���樠������
    char charUniformInit{'C'};     // �����஢����� ���樠������
    long lUniformInit{300000L};     // �����஢����� ���樠������

    std::cout << "Uniform Initialization:" << '\n';
    std::cout << "iUniformInit: " << iUniformInit << '\n';
    std::cout << "cUniformInit: " << cUniformInit << '\n';
    std::cout << "charUniformInit: " << charUniformInit << '\n';
    std::cout << "lUniformInit: " << lUniformInit << '\n';
    std::cout << '\n';

    // ���樠������ � �ᯮ�짮������ auto
    auto iAuto = 25;          // ���樠������ � �ᯮ�짮������ auto
    auto cAuto = false;      // ���樠������ � �ᯮ�짮������ auto
    auto charAuto = 'D';     // ���樠������ � �ᯮ�짮������ auto
    auto lAuto = 400000L;     // ���樠������ � �ᯮ�짮������ auto

    std::cout << "Auto Initialization:" << '\n';
    std::cout << "iAuto: " << iAuto << '\n';
    std::cout << "cAuto: " << cAuto<< '\n';
    std :: cout<< "charAuto : "<<charAuto<< '\n';
    std :: cout<<	"lAuto : "<<lAuto<< '\n';
    std::cout << '\n';
}
