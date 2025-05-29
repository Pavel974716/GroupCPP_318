/* ������ୠ� ࠡ�� �4
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
    task_8,
    task_9
};

void in_int(const std::string & prompt, int & var); // �஢�ઠ ����� int
void Task_1(); // ������� �1
void Task_2a(); // ������� �2a
void Task_2b(); // ������� �2b
void Task_3(); // ������� �3
void Task_4a(); // ������� �4a
void Task_4b(); // ������� �4b
void Task_4c(); // ������� �4�
void Task_5(); // ������� �5
void Task_6a(); // ������� �6a
void Task_6b(); // ������� �6b
void Task_7(); // ������� �7
void Task_8(); // ������� �8
void Task_9(); // ������� �9

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
            std::cout << "\na) ����� 5�5\n";
                   Task_2a();
            std::cout << "\nb) M���� 8�8\n";
                   Task_2b();
            break;
        case task_3:
            std::cout << "\n������� �3" << '\n';
            std::cout << '\n';
            Task_3();            
            break;
        case task_4:
            std::cout << "\n������� �4" << '\n';
            std::cout << '\n';
            Task_4a();
            Task_4b();
            Task_4c();
            break;
        case task_5:
            std::cout << "\n������� �5" << '\n';
            std::cout << '\n';
            Task_5();
            break;
        case task_6:
            std::cout << "\n������� �6" << '\n';
            std::cout << '\n';
            Task_6a();
            Task_6b();
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
         case task_9:
             std::cout << "\n������� �9" << '\n';
             std::cout << '\n';
             Task_9();
          break;          
    }
}

// ������� �㭪��
int main() {
    int n;
               std::cout << "��ࠢ����.\n";

      while (true) {
               in_int("\n������ ����� ������� �� 1-9: ", n);

               // �஢�ઠ �� �����⨬� ��������
               if (n < 1 || n > 9) {
                   std::cout << "�訡�� �����.\n";
                   continue; // ����訢��� ����� ������� ᭮��
               }

               Tasks mytask = static_cast<Tasks>(n);
               nymT(mytask);
               std::cout << "\n���� �� �� ��� �� �ணࠬ�� ? (y/n): ";
               std::string bukv; // ��ப� ��� �࠭���� �⢥� ���짮��⥫�

               while (true) {
                           std::cin >> bukv;

                           if (bukv == "y") {
                               std::cout << "\n���ᨡ� �� �஢���! �� ᢨ�����!\n";
                               return 0; // ��室 �� �ணࠬ��
                           } else if (bukv == "n") {
                               break; // �த������ 横� � ����訢��� ������� ᭮��
                           } else {
                               std::cout << "\n�⢥� �� �ᯮ����. ��������, ������ 'y' ��� 'n': ";
                           }
                       }
}
 return 0;
}
