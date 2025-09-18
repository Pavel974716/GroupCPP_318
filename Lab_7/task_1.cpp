#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <limits>
#include <stdexcept>

// �㭪�� ��� ������᭮�� ����� 楫��� �᫠
void in_int(const std::string & prompt, int & var) {
    std::cout << prompt;
    while (!(std::cin >> var)) {
        std::cout << "�訡�� �����.\n" << '\n' << prompt;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// ������� �㭪�� Task_1
void Task_1() {
    try {
        int n;

        // ���� �᫠ � �஢�મ� ���������
        while (true) {
            in_int("������ ����� �᫠ �������� (�� 0 �� 50): ", n);
            if (n < 0 || n > 50) {
                std::cout << "�訡�� �����.\n";
            } else {
                break;
            }
        }

        // �����⢥���� ��࠭�祭�� �� �᫮��� �����
        if (n == 9) {
            throw std::runtime_error("����� ������� 9-�� �᫮ ��������!");
        }

        // ��ࠡ�⪠ ������ ��砥�
        if (n == 0) {
            std::cout << "��᫮ �������� �0 ࠢ�� 0\n";
            return ;
        }
        if (n == 1) {
            std::cout << "��᫮ �������� �1 ࠢ�� 1\n";
            return ;
        }

        // ������⢮ ��⮪�� 䨪�஢��� = 4
        const unsigned threads_count = 4;

        // ��६���� ��� ���᫥��� �ᥫ ��������
        long long a = 0, b = 1; // ��砫�� ���祭�� F(0)=0, F(1)=1
        int step = 2;           // ��稭��� ���᫥��� � F(2)
        bool done = false;      // 䫠� ����砭��

        // ���⥪� � �᫮���� ��६����� ��� ᨭ�஭���樨
        std::mutex m;
        std::condition_variable cv;
        unsigned turn = 0; // 㪠�뢠��, ����� ��⮪ ᥩ�� ࠡ�⠥�

        // �㭪��, �믮��塞�� ��⮪��
        auto worker = [&](unsigned id) {
            std::unique_lock<std::mutex> lk(m);
            while (!done) {

                // ��� ᢮�� ��।�
                cv.wait(lk, [&]{ return done || (turn == id && step <= n); });
                if (done || step > n) break;

                // ����塞 ��।��� �᫮ ��������
                long long temp = a + b;
                a = b;
                b = temp;

                // �뢮� �⫠��筮� ���ଠ樨
                std::cout << "��⮪ " << id
                          << " ���᫨� F(" << step << ") = " << b << '\n';

                ++step; // ���室�� � ᫥���饬� 蠣�

                // ��।�� ��।� ᫥���饬� ��⮪�
                turn = (turn + 1) % threads_count;

                // �᫨ ��諨 �� ���� � �����蠥�
                if (step > n) done = true;

                // �㤨� �� ��⮪�
                cv.notify_all();
            }
        };

        // ������ ���ᨢ ��⮪��
        std::thread threads[threads_count];
        for (unsigned i = 0; i < threads_count; ++i) {
            threads[i] = std::thread(worker, i);
        }

        // ����᪠�� ���� ��⮪
        {
            std::lock_guard<std::mutex> lk(m);
            turn = 0;
        }
        cv.notify_all();

        // ���������� �����襭�� ��� ��⮪��
        for (unsigned i = 0; i < threads_count; ++i) {
            threads[i].join();
        }

        // �뢮� १����
        std::cout << "��᫮ �������� �" << n << " ࠢ�� " << b << '\n';
    }
    catch (const std::exception &ex) {
        std::cout << "�᪫�祭��: " << ex.what() << '\n';
    }
}
