/* ������ୠ� ࠡ�� �1
 * ��㯯� �318
 * Developer: ��㤥�殢 �.�.
 * OS: Windows 10 ��௮�⨢���
 * Locale (����஢��): IBM866
 */


// ������砥� ������⥪� ��� �����/�뢮��
#include <iostream>


// main - ������� �㭪�� � ���ன ��稭����� �ᯮ������ �ணࠬ��
int main()
{

// ������� 1
/* ����� ��㯯� 318
 * ���ࠡ��稪� �ணࠬ�� ��㤥�殢 ����� ���������
 * ����� ������୮� ࠡ��� 1
 * debug 70 ��
 * release 18 ��
*/

// ������� 2
std::cout << "*****";
// ��⠭�������� ࠧ��� ����
std::cout.width(25);
std::cout << "�����";
std::cout.width(25);
std::cout << "*****\n";
// ������ ������ �����
std::cout << " \n";
std::cout.width(56);
std::cout << "�������: ���. ��ࠧ������ \n";
std::cout.width(40);
std::cout << "��㯯�: 318 \n";
std::cout.width(53);
std::cout << "��㤥��: ��㤥�殢 ����� \n";
std::cout << " \n";
std::cout.width(35);
std::cout << "���� 2025 \n";
std::cout << " \n";
std::cout.width(56);
// ��⠭�������� ��ப� � ����������
std::cout.fill ('*');
std::cout << " \n";

// TODO: ������� 3
std::cout << "���᫨�� ᪮���� ��אַ��������� �������� \n";
// ��६����� ����ﭨ�
int s;
std::cout << "������ ���ﭨ� � ������ Enter \n";
std::cin >> s;
// ��६����� �६���
int t;
std::cout << "������ �६� � ������ Enter \n";
std::cin >> t;
std::cout << "������� = "<< s/t <<"\n";
std::cout << "���᫨�� �᪮७�� \n";
// ��६����� ��砫쭮� ᪮���
int vn;
std::cout << "������ ��砫��� ᪮���� � ������ Enter \n";
std::cin >> vn;
// ��६����� ����筮� ᪮���
int vk;
std::cout << "������ ������� ᪮���� � ������ Enter \n";
std::cin >> vk;
// ��६����� ��砫쭮�� �६���
int tn;
std::cout << "������ ��砫쭮� �६� � ������ Enter \n";
std::cin >> tn;
// ��६����� ����筮�� �६���
int tk;
std::cout << "������ ����筮� �६� � ������ Enter \n";
std::cin >> tk;
std::cout << "�᪮७�� = "<< (vk-vn)/(tk-tn) <<"\n";
std::cout << "���᫨�� ࠤ��� ��㣠 \n";
// ��६����� ����� ��㣠
int Lkrug;
std::cout << "������ ����� ��㣠 � ������ Enter \n";
std::cin >> Lkrug;
std::cout << "������ ��㣠 = "<< Lkrug/(2*3.14) <<"\n";

return 0;
}
