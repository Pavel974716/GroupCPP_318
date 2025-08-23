#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>

class Complex {
private:
    double re; // Действительная часть
    double im; // Мнимая часть
    static constexpr double PI = 3.14159265358979323846; // Число PI

public:
    // Конструктор с параметрами по умолчанию
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    // Геттеры
    double real() const { return re; }
    double imag() const { return im; }

    // Арифметические операторы
    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    Complex operator/(const Complex& other) const {
        double denom = other.re * other.re + other.im * other.im;
        if (denom == 0.0)
            throw std::runtime_error("Деление на ноль");
        return Complex((re * other.re + im * other.im) / denom,
                       (im * other.re - re * other.im) / denom);
    }

    // Сравнение
    bool operator==(const Complex& other) const {
        return std::abs(re - other.re) < 1e-9 && std::abs(im - other.im) < 1e-9;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Сопряжённое
    Complex conjugate() const {
        return Complex(re, -im);
    }

    // Модуль и аргумент
    double modulus() const {
        return std::sqrt(re * re + im * im);
    }

    double argument() const {
        return std::atan2(im, re);
    }

    // Возведение в степень
    Complex pow(int n) const {
        double r = std::pow(modulus(), n);
        double theta = argument() * n;
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    Complex pow(double n) const {
        double r = std::pow(modulus(), n);
        double theta = argument() * n;
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    // Извлечение корня n-й степени, k-й корень
    Complex root(int n, int k = 0) const {
        double r = std::pow(modulus(), 1.0 / n);
        double theta = (argument() + 2 * PI * k) / n;
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    // Алгебраическая форма
    std::string toAlgebraic() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(3)
            << re << (im >= 0 ? " + " : " - ") << std::abs(im) << "i";
        return oss.str();
    }

    // Тригонометрическая форма
    std::string toTrigonometric() const {
        std::ostringstream oss;
        double arg = argument();
        oss << std::fixed << std::setprecision(3)
            << modulus() << " (cos(" << arg << ") + i sin(" << arg << "))";
        return oss.str();
    }

    // Экспоненциальная форма
    std::string toExponential() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(3)
            << modulus() << " * e^(i " << argument() << ")";
        return oss.str();
    }

    // Статическое создание из форм
    static Complex fromTrigonometric(double r, double theta) {
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    static Complex fromExponential(double r, double theta) {
        return fromTrigonometric(r, theta);
    }

    // Получение всех n корней
    static Complex* roots(const Complex& z, int n) {
        Complex* result = new Complex[n];
        for (int k = 0; k < n; ++k) {
            result[k] = z.root(n, k);
        }
        return result;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
        return os << z.toAlgebraic();
    }
};

// Главная функция Task_4
void Task_4() {
    std::cout << std::fixed << std::setprecision(3);

    Complex z1(3, 4);
    Complex z2(1, -2);

    std::cout << "\nz1 (комплексное число 1) = " << z1 << '\n';
    std::cout << "z2 (комплексное число 2) = " << z2 << '\n';

    std::cout << "Сумма (z1 + z2) = " << z1 + z2 << '\n';
    std::cout << "Разность (z1 - z2) = " << z1 - z2 << '\n';
    std::cout << "Произведение (z1 * z2) = " << z1 * z2 << '\n';

    try {
        std::cout << "Частное (z1 / z2) = " << z1 / z2 << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Ошибка при делении: " << e.what() << '\n';
    }

    std::cout << "Сопряжение z1 (conj(z1)) = " << z1.conjugate() << '\n';
    std::cout << "Возведение z1 в целую степень 3: z1^3 = " << z1.pow(3) << '\n';
    std::cout << "Возведение z1 в вещественную степень 2.5: z1^2.5 = " << z1.pow(2.5) << '\n';
    std::cout << "Возведение z1 в отрицательную степень -1: z1^-1 = " << z1.pow(-1) << '\n';

    int n = 3;
    Complex* roots = Complex::roots(z1, n);
    std::cout << "Корни " << n << "-й степени из z1:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Корень " << (i + 1) << " = " << roots[i] << '\n';
    }
    delete[] roots;

    std::cout << "Алгебраическая форма z1: " << z1.toAlgebraic() << '\n';
    std::cout << "Тригонометрическая форма z1: " << z1.toTrigonometric() << '\n';
    std::cout << "Экспоненциальная форма z1: " << z1.toExponential() << std::endl;
}
