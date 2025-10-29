#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>
#include <cstdlib>
#include <ctime>

// ������� (�)
/* ����� ����� � ᯨ᮪, ������� ������ ����� �� �����
   ������� (2,4,6,...) �� ������ ᯨ᪠, ���騥 �� �������
   ������� (1,3,5,...). */
std::vector<int> mix_even_positions_with_odd_positions(const std::vector<int>& v, const std::list<int>& lst)
{
    // ����ࠥ� ������ ᯨ᪠ �� ������� �������
    std::vector<int> oddPosFromList;
    int pos = 1; // 1-based ������
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it, ++pos) {
        if (pos % 2 == 1)
            oddPosFromList.push_back(*it);
    }

    // �����塞 ������ ����� �� ����� ������� (1-based)
    std::vector<int> res = v;
    std::size_t k = 0;
    for (std::size_t i = 0; i < res.size(); ++i) {
        if ((i + 1) % 2 == 0 && k < oddPosFromList.size()) {
            res[i] = oddPosFromList[k++];
        }
    }
    return res;
}

// ������ᠫ쭠� �㭪�� ���� ���⥩��� (const-��뫪�)
template<class Container>
void print_one_line(const char* const header, const Container& c)
{
    std::cout << header << '\n';
    bool first = true;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (!first) std::cout << ' ';
        std::cout << *it;
        first = false;
    }
    std::cout << '\n';
}

// ������� (b)
// �������� � ����� ᯨ᪠<double> �����, ࠢ�� �।���� ��䬥��᪮�� ��� ��� ����⮢.
void append_mean_tail(std::list<double>& ld)
{
    if (ld.empty()) {
        ld.push_back(0.0);
        return;
    }

    long double sum = 0.0L;
    std::size_t n = 0;

    for (std::list<double>::const_iterator it = ld.begin(); it != ld.end(); ++it) {
        sum += *it;
        ++n;
    }

    const double mean = static_cast<double>(sum / static_cast<long double>(n));
    ld.push_back(mean);
}

// ������� (c)
// ���뢠�� 3 ���� (�����, ��ப�) � ������ �� �� ������.
void read_and_print_top3_berries()
{
    std::cout << "������ �ணࠬ�� ᮡ�ࠥ� ⮯-3 ���� ���� �.\n";

    std::vector<std::pair<int, std::string>> items;
    items.reserve(3);

    for (int i = 0; i < 3; ) {
        std::cout << "��������, ������ ३⨭�: ";
        int rank;
        if (!(std::cin >> rank)) {
            std::cout << "�訡�� ����� ३⨭��. ������.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "��������, ������ �������� ��: ";
        std::string name;
        std::getline(std::cin, name);

        if (name.empty()) {
            std::cout << "�������� ���⮥. ������.\n\n";
            continue;
        }

        items.push_back(std::make_pair(rank, name));
        ++i;
    }

    std::stable_sort(items.begin(), items.end(),
        [](const std::pair<int, std::string>& a,
           const std::pair<int, std::string>& b) {
            return a.first < b.first;
        });

    std::cout << "���-3 ���� ���� �:\n";
    for (std::size_t i = 0; i < items.size(); ++i) {
        std::cout << (i + 1) << ". " << items[i].second
                  << " (३⨭�: " << items[i].first << ")\n";
    }
}

// ������� �㭪�� Task_2
void Task_2()
{
    std::srand(static_cast<unsigned int>(std::time(0))); // ���樠������ �������

    // ������� (a)
    std::cout << "a) ���� ����樨 ����� � ������ ����樨 ᯨ᪠.\n";

    const int nVec = 15;   // �������塞�� ������⢮ ����⮢
    const int nList = 15;

    std::vector<int> myVector;
    std::list<int> myList;

    // ������塞 �ᥢ����砩�묨 �᫠�� [-50, 50]
    for (int i = 0; i < nVec; ++i)
        myVector.push_back(std::rand() % 101 - 50);

    for (int i = 0; i < nList; ++i)
        myList.push_back(std::rand() % 101 - 50);

    print_one_line("myVector:", myVector);
    print_one_line("myList:", myList);

    const std::vector<int> mixed = mix_even_positions_with_odd_positions(myVector, myList);
    print_one_line("���蠭�� �����:", mixed);

    // ������� (b)
    std::cout << "\nb) ���������� �।���� ��䬥��᪮�� � ����� ᯨ᪠\n";

    std::list<double> ld;
    const int count = 10; // 䨪�஢����� ������⢮ ����⮢ (�� 10)

    for (int i = 0; i < count; ++i) {
        const double val = (std::rand() % 1000) / 10.0 - 50.0; // ��砩�� [-50.0, 50.0]
        ld.push_back(val);
    }

    print_one_line("���᮪ (��):", ld);
    append_mean_tail(ld);
    print_one_line("���᮪ (��᫥ ���������� �।����):", ld);

    // ������� (c)
    std::cout << "\nc) ���஢�� ���� ���� �\n";
    read_and_print_top3_berries();
}


