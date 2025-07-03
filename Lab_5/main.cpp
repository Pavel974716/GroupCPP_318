/* ������ୠ� ࠡ�� �5
 * ��㯯� �318
 * Developer: ��㤥�殢 �.�.
 * OS: Windows 10 ��௮�⨢���
 * Locale (����஢��): IBM866
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

void in_int(const std::string & prompt, int & var); // �㭪�� ������᭮�� ����� 楫��� �᫠
std::string in_string(const std::string& prompt); // �㭪�� ������᭮�� ����� ��ப�
extern int main();
void Task_1(); // ������� �1
void Task_2(); // ������� �2
void Task_3(); // ������� �3
void Task_4(); // ������� �4
void Task_5(); // ������� �5
void Task_6(); // ������� �6
void Task_7(); // ������� �7
void Task_8(); // ������� �8

// �㭪�� �믮������ �������
void nymT(Tasks task) {
    switch (task) {
        case task_1:
            std::cout << "\n������� �1" << '\n';
            std::cout << '\n';
            Task_1();
            break;
        case task_2:
            std::cout << "\n������� �2" << '\n';
            std::cout << '\n';
            Task_2();
            break;
        case task_3:
            std::cout << "\n������� �3" << '\n';
            std::cout << '\n';
            Task_3();
            break;
        case task_4:
            std::cout << "\n������� �4" << '\n';
            std::cout << '\n';
            Task_4();
            break;
        case task_5:
            std::cout << "\n������� �5" << '\n';
            std::cout << '\n';
            Task_5();
            break;
        case task_6:
            std::cout << "\n������� �6" << '\n';
            std::cout << '\n';
            Task_6();
            break;
        case task_7:
            std::cout << "\n������� �7" << '\n';
            std::cout << '\n';
            Task_7();
            break;
        case task_8:
            std::cout << "\n������� �8" << '\n';
            std::cout << '\n';
            Task_8();
            break;         
    }
}

// ������� �㭪��
int main() {    
    int n;
               std::cout << "��ࠢ����.\n";

      while (true) {
               in_int("\n������ ����� ������� �� 1-8: ", n);

               // �஢�ઠ �� �����⨬� ��������
               if (n < 1 || n > 8) {
                   std::cout << "�訡�� �����.\n";
                   continue; // ����訢��� ����� ������� ᭮��
               }

               Tasks mytask = static_cast<Tasks>(n);
               nymT(mytask);               

               while (true) {                          
                           std::string bukv = in_string("\n���� �� �� ��� �� �ணࠬ�� ? (y/n): ");

                           if (bukv == "y" || bukv == "Y") {
                               std::cout << "\n���ᨡ� �� �஢���! �� ᢨ�����!\n";
                               return 0; // ��室 �� �ணࠬ��
                           } else if (bukv == "n" || bukv == "N") {
                               break; // �த������ 横� � ����訢��� ������� ᭮��
                           } else {
                               std::cout << "\n�⢥� �� �ᯮ����. ��������, ������ 'y' ��� 'n': ";
                           }
                       }
}
 return 0;
}
