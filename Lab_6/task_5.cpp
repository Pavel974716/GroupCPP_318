#include <iostream>
#include <algorithm>
#include <string>
#include <limits>

class Model3D; // �।���⥫쭮� �������

// ����� "��௨�"
class Brick {
private:
    int height, length, width;

public:
    static int scale; // ����᪠� ��६����� ����⠡� (�� �� ᨬ���)

    // ��������� � �⠭����묨 ࠧ��ࠬ� ��௨�
    Brick(int h = 65, int l = 250, int w = 120) : height(h), length(l), width(w) {}

    friend bool canFit(const Brick& brick, const Model3D& model);
    void displayProjections() const;

    // ����᪨� ��⮤ ��� �ᮢ���� �஥�権 � �������� ࠧ��஢
    static void drawProjection(int width, int height, const std::string& label, int w_mm, int h_mm);
};

// ����� "3D ������ �⢥����"
class Model3D {
private:
    int height, length, width;

public:
    Model3D(int h, int l, int w) : height(h), length(l), width(w) {}

    friend bool canFit(const Brick& brick, const Model3D& model);
    void displayProjections() const;
};

// ���樠������ ����᪮� ��६����� ����⠡�
int Brick::scale = 10;

// ����᪨� ��⮤ �ᮢ���� �஥�樨 ��אַ㣮�쭨��
void Brick::drawProjection(int width, int height, const std::string& label, int w_mm, int h_mm) {
    int w = width / scale;
    int h = height / scale;

    if (w < 2) w = 2;
    if (h < 2) h = 2;

    std::cout << label << " " << w_mm << " �� x " << h_mm << " ��\n";

    // ������ �࠭��
    for (int i = 0; i < w; ++i)
        std::cout << "*";
    std::cout << "\n";

    // ������ �࠭���
    for (int i = 0; i < h - 2; ++i) {
        std::cout << "*";
        for (int j = 0; j < w - 2; ++j)
            std::cout << " ";
        std::cout << "*\n";
    }

    // ������ �࠭��
    for (int i = 0; i < w; ++i)
        std::cout << "*";
    std::cout << "\n\n";
}

// �⮡ࠦ���� �஥�権 ��௨�
void Brick::displayProjections() const {
    std::cout << "\n�஥�樨 ��௨�\n";
    drawProjection(length, height, "��஭� �1 (����� x ����):", length, height);
    drawProjection(width, height, "��஭� �2 (�ਭ� x ����):", width, height);
    drawProjection(length, width, "��஭� �3 (����� x �ਭ�):", length, width);
}

// �⮡ࠦ���� �஥�権 �⢥����
void Model3D::displayProjections() const {
    std::cout << "�஥�樨 �⢥����\n";
    Brick::drawProjection(length, height, "��஭� �1 (����� x ����):", length, height);
    Brick::drawProjection(width, height, "��஭� �2 (�ਭ� x ����):", width, height);
    Brick::drawProjection(length, width, "��஭� �3 (����� x �ਭ�):", length, width);
}

// �஢�ઠ: �ன��� �� ��௨� � �⢥��⨥
bool canFit(const Brick& brick, const Model3D& model) {
    int bh[] = {brick.height, brick.length, brick.width};
    std::sort(bh, bh + 3);

    int mh[] = {model.height, model.length, model.width};
    std::sort(mh, mh + 3);

    return (bh[0] <= mh[0] && bh[1] <= mh[1] && bh[2] <= mh[2]);
}

// �������� ���� ������⥫쭮�� ���祭��
int inputPositive(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������ ����. ��������, ������ ������⥫쭮� �᫮.\n";
        } else {
            return value;
        }
    }
}

// ������� �㭪�� Task_5
void Task_5() {
    std::cout << "\n������ ࠧ���� 3D �⢥���� (� ����������):\n";

    int h = inputPositive("����: ");
    int l = inputPositive("�����: ");
    int w = inputPositive("��ਭ�: ");

    // �⠭����� ��௨� (65 x 250 x 120 ��)
    Brick brick;
    Model3D model(h, l, w);

    // �뢮� �஥�権
    brick.displayProjections();
    model.displayProjections();

    // �஢�ઠ ᮮ⢥��⢨�
    if (canFit(brick, model)) {
        std::cout << "��௨� �ன��� � �⢥��⨥.\n";
    } else {
        std::cout << "��௨� �� �ன��� � �⢥��⨥.\n";
    }
}
