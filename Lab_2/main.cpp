/* ������ୠ� ࠡ�� �2
 * ��㯯� �318
 * Developer: ��㤥�殢 �.�.
 * OS: Windows 10 ��௮�⨢���
 * Locale (����஢��): IBM866
 */


// ������砥� ������⥪� ��� �����/�뢮��
#include <iostream>
#include <bitset>
#include <cmath>
enum kon_en
{
    kon_en1 = 5,
    kon_en2 = 4,
    kon_en3 = 3,
    kon_en4 = 2,
    kon_en5 = 6,
    kon_en6 = 7,
};

// main - ������� �㭪�� � ���ன ��稭����� �ᯮ������ �ணࠬ��
int main()
{

// ������� 1
std::cout << "������� �1 \n";
std::cout << '\n';
// ��६����� ������, ���� ������ ������ ��� ����楢
int Vozrast;
std::cout << "������ ������ � ������ Enter \n";
std::cin >> Vozrast;
// ��६����� ���
float Ves;
std::cout << "������ ��� � �����ࠬ��� � ������ Enter \n";
std::cin >> Ves;
// ��६����� ���
float Rost;
std::cout << "������ ��� � ᠭ⨬���� � ������ Enter \n";
std::cin >> Rost;
// ��६����� ���� (��稭� ��� ���騭�)
bool Pol;
std::cout << "������ 1 �᫨ ��稭�, 0 �᫨ ���騭�, � ������ Enter \n";
std::cin >> Pol;
std::cout << "������ �����쭮�� ��� \n";

if (Pol==1)
   {
   std::cout << "�) - �� ��㫥 �ப� ��� ��稭 = " << (Rost-100.0f)*0.9f << '\n';
   }
if (Pol==0)
   {
    std::cout << "�) - �� ��㫥 �ப� ��� ���騭 = " << (Rost-100.0f)*0.85f << '\n';
   }
// ���� ������ ����� ⥫�
float Index = Ves/(Rost*0.01f*Rost*0.01f);
std::cout << "b) - ������� ��� �� ������� ����� ⥫� = " << Index << '\n';
// ��⠭���� �������� �� ������� ����� ⥫�
if (Index<16.0f)
   {
    std::cout << "�������: ��ࠦ��� ����� ����� \n";
   }
if (16.0f<Index && Index<18.5f)
   {
    std::cout << "�������: �������筠� (�����) ����� ⥫� \n";
   }
if (18.5f<Index && Index<25.0f)
   {
    std::cout << "�������: ��ଠ \n";
   }
if (25.0f<Index && Index<30.0f)
   {
    std::cout << "�������: �����筠� ���� ⥫� (�।���७��) \n";
   }
if (30.0f<Index && Index<35.0f)
   {
    std::cout << "�������: ���७�� ��ࢮ� �⥯��� \n";
   }
if (35.0f<Index && Index<40.0f)
   {
    std::cout << "�������: ���७�� ��ன �⥯��� \n";
   }
if (40.0f<Index)
   {
    std::cout << "�������: ���७�� ���쥩 �⥯��� (��ࡨ����) \n";
   }
// ������� �� ������ ����� � ��⮬ ������.
std::cout << "c) - �� ������� ����� ⥫� � ��⮬ ������ \n";
// ������� �� ������ ����� � ��⮬ ������ ��� ��稭.
if (Pol==1)
   {
   if (19<=Vozrast && Vozrast<=24)
      {
       if (Index<21.4f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>26.4f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (21.4f<Index && Index<26.4f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (25<=Vozrast && Vozrast<=34)
      {
       if (Index<21.6f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>26.6f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (21.6f<Index && Index<26.6f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (35<=Vozrast && Vozrast<=44)
      {
       if (Index<22.9f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>27.9f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (22.9f<Index && Index<27.9f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (45<=Vozrast && Vozrast<=54)
      {
       if (Index<25.8f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>30.8f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (25.8f<Index && Index<30.8f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (55<Vozrast)
      {
       if (Index<26.6f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>31.6f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (26.6f<Index && Index<31.6f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   }
// ������� �� ������ ����� � ��⮬ ������ ��� ���騭.
if (Pol==0)
   {
   if (19<=Vozrast && Vozrast<=24)
      {
       if (Index<19.5f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>24.5f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (19.5f<Index && Index<24.5f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (25<=Vozrast && Vozrast<=34)
      {
       if (Index<23.2f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>28.2f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (23.2f<Index && Index<28.2f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (35<=Vozrast && Vozrast<=44)
      {
       if (Index<23.4f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>28.4f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (23.4f<Index && Index<28.4f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (45<=Vozrast && Vozrast<=54)
      {
       if (Index<25.2f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>30.2f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (25.2f<Index && Index<30.2f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   if (55<Vozrast)
      {
       if (Index<27.3f)
          {
           std::cout << "�������: ����� ����� ⥫� \n";
          }
       if (Index>32.3f)
          {
           std::cout << "������: �஡����� � ��譨� ��ᮬ \n";
          }
       if (27.3f<Index && Index<32.3f)
          {
           std::cout << "�������: ��� � ��ଥ \n";
          }
      }
   }
std::cout << '\n';

// ������� 2
// ������� 2.1
std::cout << "������� �2 \n";
std::cout << '\n';
std::cout << "bool:\t" << sizeof(bool) << " bytes; \n";
std::cout << "int:\t" << sizeof(int) << "bytes; \n";
std::cout << "char:\t" << sizeof(char) << "bytes; \n";
std::cout << "float:\t" << sizeof(float) << "bytes; \n";
std::cout << "double:\t" << sizeof(double) << "bytes; \n";
std::cout << '\n';

// ������� 2.2
unsigned int ugint;
std::cout << "unsigned int:\t\t" << sizeof(ugint) << "bytes; \n";
signed int sgint;
std::cout << "signed int:\t\t" << sizeof(sgint) << "bytes; \n";
short int shint;
std::cout << "short int:\t\t" << sizeof(shint) << "bytes; \n";
long int llint;
std::cout << "long int:\t\t" << sizeof(llint) << "bytes; \n";
unsigned char ugchar;
std::cout << "unsigned char:\t\t" << sizeof(ugchar) << " bytes; \n";
signed char sgchar;
std::cout << "signed char:\t\t" << sizeof(sgchar) << "bytes; \n";
unsigned short ugshort;
std::cout << "unsigned short:\t\t" << sizeof(ugshort) << "bytes; \n";
signed short sgshort;
std::cout << "signed short:\t\t" << sizeof(sgshort) << " bytes; \n";
unsigned long uglong;
std::cout << "unsigned long:\t\t" << sizeof(uglong) << "bytes; \n";
signed long sglong;
std::cout << "signed long:\t\t" << sizeof(sglong) << "bytes; \n";
unsigned long long ugllong;
std::cout << "unsigned long long:\t" << sizeof(ugllong) << "bytes; \n";
signed long long sgllong;
std::cout << "signed long long:\t" << sizeof(sgllong) << "bytes; \n";
long double lli;
std::cout << "long double:\t\t" << sizeof(lli) << "bytes; \n";
std::cout << '\n';

// ������� 2.3
std::cout << "unsigned int: \n";
std::cout << std::hex << '\t' << "hex: " << " �� "  << 0 << " �� " << 65535 << '\n';
std::cout << std::dec << '\t' << "dec: " << " �� "  << 0 << " �� " << 65535 << '\n';
std::cout << '\t' << "bin: " << " �� "  <<  std::bitset <16>(0) << " �� " << std::bitset <16>(65535) << '\n';
std::cout << "unsigned char: \n";
std::cout << std::hex << '\t' << "hex: " << " �� "  << 0 << " �� " << 255 << '\n';
std::cout << std::dec << '\t' << "dec: " << " �� "  << 0 << " �� " << 255 << '\n';
std::cout << '\t' << "bin: " << " �� "  <<  std::bitset <8>(0) << " �� " << std::bitset <8>(255) << '\n';
std::cout << "unsigned long: \n";
std::cout << std::hex << '\t' << "hex: " << " �� "  << 0 << " �� " << 4294967295 << '\n';
std::cout << std::dec << '\t' << "dec: " << " �� "  << 0 << " �� " << 4294967295 << '\n';
std::cout << '\t' << "bin: " << " �� "  <<  std::bitset <32>(0) << " �� " << std::bitset <32>(4294967295) << '\n';
std::cout << "unsigned shot: \n";
std::cout << std::hex << '\t' << "hex: " << " �� "  << 0 << " �� " << 65535 << '\n';
std::cout << std::dec << '\t' << "dec: " << " �� "  << 0 << " �� " << 65535 << '\n';
std::cout << '\t' << "bin: " << " �� "  <<  std::bitset <16>(0) << " �� " << std::bitset <16>(4294967295) << '\n';
std::cout << '\n';

// ������� 3
std::cout << "������� �3 \n";
std::cout << '\n';
// ��।��塞 ��६����
float a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
std::cout << "������ 10 �ᥫ � ������饩 �窮� � ������ Enter \n";
std::cout << "1 �᫮ = ";
std::cin >> a1;
std::cout << "2 �᫮ = ";
std::cin >> a2;
std::cout << "3 �᫮ = ";
std::cin >> a3;
std::cout << "4 �᫮ = ";
std::cin >> a4;
std::cout << "5 �᫮ = ";
std::cin >> a5;
std::cout << "6 �᫮ = ";
std::cin >> a6;
std::cout << "7 �᫮ = ";
std::cin >> a7;
std::cout << "8 �᫮ = ";
std::cin >> a8;
std::cout << "9 �᫮ = ";
std::cin >> a9;
std::cout << "10 �᫮ = ";
std::cin >> a10;
std::cout << "������� = " << (a1+a2+a3+a4+a5+a6+a7+a8+a9+a10)/10 << '\n';
std::cout << '\n';


// ������� 4
std::cout << "������� �4 \n";
std::cout << '\n';
double d1 (3.450e1);
std::cout << "���� 34.50 " << "<3.450e1> " << "����祭� = " << d1 << '\n';
double d2 (4000e-6);
std::cout << "���� 0.004000 " << "<4000e-6> " << "����祭� = " << d2 << '\n';
double d3 (1.23005e2);
std::cout << "���� 123.005 " << "<1.23005e2> " << "����祭� = " << d3 << '\n';
double d4 (1.46e5);
std::cout << "���� 146000 " << "<1.46e5> " << "����祭� = " << d4 << '\n';
std::cout << '\n';


// ������� 5
std::cout << "������� �5 \n";
std::cout << '\n';

// ������� 5.1
//TODO �� ���� ��祬� ����ન���� true � false???
std::cout << "������� �5.1 \n";
std::cout << ((true && true) || false) << '\n';
std::cout << ((false && true) || true) << '\n';
std::cout << ((false && true) || false || true) << '\n';
std::cout << ((5 > 6 || 4 > 3) && (7 > 8)) << '\n';
std::cout << (!(7 > 6 || 3 > 4)) << '\n';
std::cout << '\n';

// ������� 5.2
//TODO �� ���� ��祬� ����ન���� && � || ???
std::cout << "������� �5.2 \n";
const bool k1 (true);
const bool k2 (true);
const bool k3 (true);
const bool k4 (false);
const bool k5 (false);
const bool k6 (false);
std::cout << ((k1 && k2) || (!k3) && (k4 || k5)) << '\n';
std::cout << ((k1 && k2) || (k3 && k4) || (!k5)) << '\n';
std::cout << ((k1 || k2) && (k3 || k4) && (k4 || k6)) << '\n';
std::cout << "enum \n";
// ���
std::cout << ((kon_en1 > kon_en2) && (kon_en3 < kon_en4) && (kon_en5 != kon_en6)) << '\n';
std::cout << '\n';

// ������� 5.3
std::cout << "������� �5.3 \n";
bool a (false);
bool b (true);
std::cout << (!(a && b)) << "=" << ((!a) || (!b)) << '\n';
std::cout << (!(a || b)) << "=" << ((!a) && (!b)) << '\n';
std::cout << '\n';

// ������� 5.4
std::cout << "������� �5.4 \n";
int x, y, z, v;
bool logicValue;
std::cout << "������ 4 楫��᫥��� �᫠ \n";
// ��ᢠ���� ��砫�� ���祭�� ��६����
std::cin >> x >> y >> z >> v;
std::cout << "������ �������� ��६����� 0 ��� 1 \n";
std::cin >> logicValue;
// � - �ਢᢠ�������� ��㣮� ���祭�� �㬬� �ᥫ
x = 3 + 4 + 5;
std::cout << "x = " << x << "; y = " << y << "; z = " << z << "; v = " << v << '\n';
// x � y ��ᢠ�������� ���祭�� z
x = y = z;
std::cout << "x = " << x << "; y = " << y << "; z = " << z << "; v = " << v << '\n';
// � 㢥��稢������ ���६��⮬ (++) �� 1, � z �����砥��� ��砫쭮� ���祭�� 㬭������ (y+1)+5
z *= ++y + 5;
std::cout << "x = " << x << "; y = " << y << "; z = " << z << "; v = " << v << '\n';
logicValue = x || y && z || v;
// x,y �� 楫��᫥���, � z,v ������ ࠢ�� ���� ���
std::cout << "logicValue = " << logicValue << '\n';
std::cout << '\n';


// ������� 5.5
std::cout << "������� �5.5 \n";
int chislo, stvig, step;
std::cout << "������ �᫮ �� 0 �� 2 \n";
std::cin >> chislo;
std::cout << "������ �᫮ �� ���஥ ����室��� ᤢ����� �� 1 �� 11 \n";
std::cin >> stvig;
step = pow (chislo, 4);
std::cout << std::dec << "10-� ���� " << (step << stvig) << '\n';
std::cout << std::hex << "16-� ���� " << (step << stvig) << '\n';
std::cout << std::oct << "8-� ���� " << (step << stvig) << '\n';
std::cout << "2-� ���� " <<  std::bitset <16>((step << stvig)) << '\n';
std::cout << '\n';

/* ������� 5.6
int res = a + b * 1 ? 128/5; 㬭������, �������, ᫮�����, ?
int res = a | b >> 1; ����⮢� ᤢ�� ��ࠢ�,����⮢�� ���
int res = a /b* k; �������, 㬭������
*/




return 0;
}
