#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>

class InfoConverter {
private:
    double value_; // ����񭭮� ���祭��
    int unit_id_; // 1..6 (bit, B, KB, MB, GB, MiB)
    double bytes_; // ���祭�� � ����� (����)

    static double pow2(int p) { return std::ldexp(1.0, p); } // 2^p, ��� ���� �筮��

public:
    InfoConverter() : value_(0.0), unit_id_(2), bytes_(0.0) {}

    static void clear_stdin() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void showMenu() const {
        std::cout << "�롥�� ������� ����७��:\n"
                  << "  1) bit (���)\n"
                  << "  2) B   (����)\n"
                  << "  3) KB  (10^3 ����)\n"
                  << "  4) MB  (10^6 ����)\n"
                  << "  5) GB  (10^9 ����)\n"
                  << "  6) MiB (2^20 ����)\n";
    }

    void input() {
        // ���� ���祭�� � �஢�મ�
        std::cout << "������ �᫮ (���祭��, �� 0 �� 1 000 000 000): ";
        while (true) {
            if (std::cin >> value_) {
                if (value_ >= 0 && value_ <= 1e9) break;
                std::cout << "�訡��! ��᫮ ������ ���� � ��������� �� 0 �� 1e9.\n\n";
            } else {
                std::cout << "�訡�� �����. ������ �᫮.\n\n";
            }
            clear_stdin();

            std::cout << "������ �᫮ (���祭��, �� 0 �� 1 000 000 000): ";
        }

        // ���� �롮� �������
        showMenu();
        std::cout << "��� �롮� (1..6): ";
        while (!(std::cin >> unit_id_) || unit_id_ < 1 || unit_id_ > 6) {
            std::cout << "�訡��! ������ 楫�� �᫮ �� 1 �� 6.\n��� �롮� (1..6): \n";
            clear_stdin();
        }
        clear_stdin();

        toBytes();
    }

    void toBytes() {
        switch (unit_id_) {
            case 1: // bit
                bytes_ = value_ / 8.0;
                break;
            case 2: // B
                bytes_ = value_;
                break;
            case 3: // KB (10^3)
                bytes_ = value_ * 1e3;
                break;
            case 4: // MB (10^6)
                bytes_ = value_ * 1e6;
                break;
            case 5: // GB (10^9)
                bytes_ = value_ * 1e9;
                break;
            case 6: // MiB (2^20)
                bytes_ = value_ * pow2(20);
                break;
            default:
                bytes_ = value_;
        }

        // �஢�ઠ �� ��९������� double
        if (bytes_ > 1e18) {
            std::cout << "�।�०�����: ���祭�� ᫨誮� ������, ����� ���� �����.\n";
        }
    }

    void printAll() const {
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "\n�८�ࠧ������:\n";
        std::cout << "----------------------------\n";
        std::cout << "��������� (GB): " << (bytes_ / 1e9) << '\n';
        std::cout << "��������� (MB): " << (bytes_ / 1e6) << '\n';
        std::cout << "��������� (KB): " << (bytes_ / 1e3) << '\n';
        std::cout << "����� (B):      " << bytes_ << '\n';
        std::cout << "���� (bit):     " << (bytes_ * 8.0) << '\n';
        std::cout << "��������� (MiB):" << (bytes_ / pow2(20)) << '\n';
        std::cout << "----------------------------\n";
    }
};

// ������� �㭪�� Task_3
void Task_3() {
    InfoConverter conv;
    conv.input();
    conv.printAll();
}

