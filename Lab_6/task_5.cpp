#include <iostream>
#include <algorithm>
#include <string>
#include <limits>

class Model3D; // Предварительное объявление

// Класс "Кирпич"
class Brick {
private:
    int height, length, width;

public:
    static int scale; // Статическая переменная масштаба (мм на символ)

    // Конструктор со стандартными размерами кирпича
    Brick(int h = 65, int l = 250, int w = 120) : height(h), length(l), width(w) {}

    friend bool canFit(const Brick& brick, const Model3D& model);
    void displayProjections() const;

    // Статический метод для рисования проекций с подписью размеров
    static void drawProjection(int width, int height, const std::string& label, int w_mm, int h_mm);
};

// Класс "3D модель отверстия"
class Model3D {
private:
    int height, length, width;

public:
    Model3D(int h, int l, int w) : height(h), length(l), width(w) {}

    friend bool canFit(const Brick& brick, const Model3D& model);
    void displayProjections() const;
};

// Инициализация статической переменной масштаба
int Brick::scale = 10;

// Статический метод рисования проекции прямоугольника
void Brick::drawProjection(int width, int height, const std::string& label, int w_mm, int h_mm) {
    int w = width / scale;
    int h = height / scale;

    if (w < 2) w = 2;
    if (h < 2) h = 2;

    std::cout << label << " " << w_mm << " мм x " << h_mm << " мм\n";

    // Верхняя граница
    for (int i = 0; i < w; ++i)
        std::cout << "*";
    std::cout << "\n";

    // Боковые границы
    for (int i = 0; i < h - 2; ++i) {
        std::cout << "*";
        for (int j = 0; j < w - 2; ++j)
            std::cout << " ";
        std::cout << "*\n";
    }

    // Нижняя граница
    for (int i = 0; i < w; ++i)
        std::cout << "*";
    std::cout << "\n\n";
}

// Отображение проекций кирпича
void Brick::displayProjections() const {
    std::cout << "\nПроекции кирпича\n";
    drawProjection(length, height, "Сторона №1 (длина x высота):", length, height);
    drawProjection(width, height, "Сторона №2 (ширина x высота):", width, height);
    drawProjection(length, width, "Сторона №3 (длина x ширина):", length, width);
}

// Отображение проекций отверстия
void Model3D::displayProjections() const {
    std::cout << "Проекции отверстия\n";
    Brick::drawProjection(length, height, "Сторона №1 (длина x высота):", length, height);
    Brick::drawProjection(width, height, "Сторона №2 (ширина x высота):", width, height);
    Brick::drawProjection(length, width, "Сторона №3 (длина x ширина):", length, width);
}

// Проверка: пройдет ли кирпич в отверстие
bool canFit(const Brick& brick, const Model3D& model) {
    int bh[] = {brick.height, brick.length, brick.width};
    std::sort(bh, bh + 3);

    int mh[] = {model.height, model.length, model.width};
    std::sort(mh, mh + 3);

    return (bh[0] <= mh[0] && bh[1] <= mh[1] && bh[2] <= mh[2]);
}

// Безопасный ввод положительного значения
int inputPositive(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Пожалуйста, введите положительное число.\n";
        } else {
            return value;
        }
    }
}

// Главная функция Task_5
void Task_5() {
    std::cout << "\nВведите размеры 3D отверстия (в миллиметрах):\n";

    int h = inputPositive("Высота: ");
    int l = inputPositive("Длина: ");
    int w = inputPositive("Ширина: ");

    // Стандартный кирпич (65 x 250 x 120 мм)
    Brick brick;
    Model3D model(h, l, w);

    // Вывод проекций
    brick.displayProjections();
    model.displayProjections();

    // Проверка соответствия
    if (canFit(brick, model)) {
        std::cout << "Кирпич пройдет в отверстие.\n";
    } else {
        std::cout << "Кирпич НЕ пройдет в отверстие.\n";
    }
}
