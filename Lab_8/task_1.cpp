#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <iomanip>
#include <limits>

// �������� ���� 楫��� �᫠ � �������� ���������
void in_int(const std::string& prompt, int& var, int min = 1, int max = 1000) {
    while (true) {
        std::cout << prompt;
        if (std::cin >> var) {
            if (var >= min && var <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break; // ���४⭮� ���祭��
            } else {
                std::cout << "�訡��! ��᫮ ������ ���� � ��������� �� "
                          << min << " �� " << max << ".\n\n";
            }
        } else {
            std::cout << "�訡��! ������ 楫�� �᫮!\n\n";
            std::cin.clear(); // ��� 䫠��� �訡��
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���⪠ ����
    }
}

// ��ॣ�㧪� ������ �뢮�� ��� std::vector<int>
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    const std::size_t per_line = 10;
    for (std::size_t i = 0; i < v.size(); ++i) {
        out << std::setw(11) << v[i] << ' ';
        if ((i + 1) % per_line == 0) out << '\n';
    }
    return out;
}

// ��������� �㭪�� ��� �뢮�� ���⥩���
template <typename Container>
void printContainer(const Container& cont) {
    std::cout << "��אַ� ���冷�:\n";
    for (auto it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << ' ';

    std::cout << "\n����� ���冷�:\n";
    for (auto rit = cont.rbegin(); rit != cont.rend(); ++rit)
        std::cout << *rit << ' ';

    std::cout << '\n';
}

// ������� �㭪�� Task_1
void Task_1() {

    // ������� (a)
    std::cout << "a) ������� ���⥩���, �뢮�, ������� 㭨������ \n";

    // ���뢠�� ������⢮ ����⮢ (� ���⮩)
    int N = 0;
    in_int("������ ������⢮ ����⮢ N (�� 1 �� 1000): ", N, 1, 1000);

    // ����ࠨ���� ������� ��砩��� �ᥫ
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-2000000000, 2000000000);

    // ������㥬 ���⥩���
    std::vector<int> data;
    data.reserve(static_cast<std::size_t>(N));
    for (int i = 0; i < N; ++i)
        data.push_back(dist(gen));

    // �뢮��� ᮤ�ন��� ���⥩��� (�� 10 ����⮢ � ��ப�)
    std::cout << "����ন��� ���⥩���:\n";
    std::cout << data << '\n';

    // ������뢠�� ������⢮ 㭨������ ����⮢
    std::set<int> unique_values(data.begin(), data.end());
    std::cout << "��������� �ᥫ: " << unique_values.size() << '\n';

    // ������� (b)
    std::cout << "\nb) �뢮� ���⥩��� � ��אַ� � ���⭮� ���浪� \n";
    printContainer(data);
}


