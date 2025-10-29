#include "ring_buffer.h"
#include <thread>
#include <chrono>
#include <atomic>
#include <limits>
#include <iostream>

// ������� �㭪�� Task_5
void Task_5() {
    try {

        // ����� ����� ࠧ��� (񬪮���) ����楢��� ���� - 8 ����⮢
        RingBuffer rb(8);

        std::cout << "a) �஢�ઠ ����楢��� ���� \n";
        std::cout << "���� ᮧ������ �� 8 ����⮢.\n"
                       << "��⮪ �����뢠�� �������騥 �᫠ ����� 200 ��.\n"
                       << "��᫥ ���������� ���� ����� ������ ���� (wrap-around).\n"
                       << "��� ��室� ������ 'q' � ������ Enter.\n\n";

        // �����⮢�� 䮭����� ��⮪�
        std::atomic<bool> running(true);       

        // ������ ��⮪: ॣ��୮ �������� ���祭�� � ����
        std::thread writer([&]() {
            int x = 1;  // �㤥� ����� 1, 2, 3, ...
            while (running.load()) {
                rb + x;   // ������ ��।���� ���祭��
                ++x;

                // �뢮��� ⥪�饥 ���ﭨ�            
                std::cout << "\r����: " << rb
                               << "   | head=" << rb.head_index()
                               << " size=" << rb.size()
                               << "  ������ �������... "
                               << std::flush;

                // ��㧠 200 ��
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
        });

        while (true) {
            std::string input;
            if (!(std::cin >> input)) {                
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                
                continue;
            }            

            if (input.size() != 1) {
                std::cout << "����ୠ� �������. ������ ���� �㪢�.\n\n";
                continue;
            }

            char ch = input[0];
            if (ch == 'q' || ch == 'Q') {
                break;
            } else {
                std::cout << "�������⭠� �������. ��� ��室� ������ 'q'.\n\n";
            }
        }
        std::cout << '\n';

        running.store(false);            // ᮮ�頥� ��⮪� ��� ����������
        if (writer.joinable()) writer.join();  // ���������� �����襭��

        std::cout << "�⮣���� ���ﭨ� ����\n";
        std::cout << rb << "\n\n";
        std::cout << "b) �뢮� ᮤ�ন���� \n";
        std::cout << "�� ������ ����:\n" << rb << '\n';

        // �뢮� ��������� �����᪨� �����ᮢ [2..5]
        // �஢��塞, �� ����⮢ �����筮 (�㦭� ������ 6)
        if (rb.size() > 5) {
            std::cout << "�������� � ������ 2 �� 5:\n";
            rb.printRange(std::cout, 2, 5); // ���⠥� ������ 2,3,4,5 (�����᪨� �������)
            std::cout << '\n';
        } else {
            std::cout << "�������筮 ����⮢ ��� �뢮�� ��������� [2..5] (size=" << rb.size() << ")\n";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n�ணࠬ�� �����襭�.\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "�訡��: " << ex.what() << '\n';
    }
}


