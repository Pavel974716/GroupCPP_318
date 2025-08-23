#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>

class Complex {
private:
    double re; // ����⢨⥫쭠� ����
    double im; // ������ ����
    static constexpr double PI = 3.14159265358979323846; // ��᫮ PI

public:
    // ��������� � ��ࠬ��ࠬ� �� 㬮�砭��
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    // ������
    double real() const { return re; }
    double imag() const { return im; }

    // ��䬥��᪨� �������
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
            throw std::runtime_error("������� �� ����");
        return Complex((re * other.re + im * other.im) / denom,
                       (im * other.re - re * other.im) / denom);
    }

    // �ࠢ�����
    bool operator==(const Complex& other) const {
        return std::abs(re - other.re) < 1e-9 && std::abs(im - other.im) < 1e-9;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // �����񭭮�
    Complex conjugate() const {
        return Complex(re, -im);
    }

    // ����� � ��㬥��
    double modulus() const {
        return std::sqrt(re * re + im * im);
    }

    double argument() const {
        return std::atan2(im, re);
    }

    // ���������� � �⥯���
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

    // �����祭�� ���� n-� �⥯���, k-� ��७�
    Complex root(int n, int k = 0) const {
        double r = std::pow(modulus(), 1.0 / n);
        double theta = (argument() + 2 * PI * k) / n;
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    // �����ࠨ�᪠� �ଠ
    std::string toAlgebraic() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(3)
            << re << (im >= 0 ? " + " : " - ") << std::abs(im) << "i";
        return oss.str();
    }

    // �ਣ��������᪠� �ଠ
    std::string toTrigonometric() const {
        std::ostringstream oss;
        double arg = argument();
        oss << std::fixed << std::setprecision(3)
            << modulus() << " (cos(" << arg << ") + i sin(" << arg << "))";
        return oss.str();
    }

    // ��ᯮ���樠�쭠� �ଠ
    std::string toExponential() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(3)
            << modulus() << " * e^(i " << argument() << ")";
        return oss.str();
    }

    // ����᪮� ᮧ����� �� ��
    static Complex fromTrigonometric(double r, double theta) {
        return Complex(r * std::cos(theta), r * std::sin(theta));
    }

    static Complex fromExponential(double r, double theta) {
        return fromTrigonometric(r, theta);
    }

    // ����祭�� ��� n ��୥�
    static Complex* roots(const Complex& z, int n) {
        Complex* result = new Complex[n];
        for (int k = 0; k < n; ++k) {
            result[k] = z.root(n, k);
        }
        return result;
    }

    // ������ �뢮��
    friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
        return os << z.toAlgebraic();
    }
};

// ������� �㭪�� Task_4
void Task_4() {
    std::cout << std::fixed << std::setprecision(3);

    Complex z1(3, 4);
    Complex z2(1, -2);

    std::cout << "\nz1 (�������᭮� �᫮ 1) = " << z1 << '\n';
    std::cout << "z2 (�������᭮� �᫮ 2) = " << z2 << '\n';

    std::cout << "�㬬� (z1 + z2) = " << z1 + z2 << '\n';
    std::cout << "�������� (z1 - z2) = " << z1 - z2 << '\n';
    std::cout << "�ந�������� (z1 * z2) = " << z1 * z2 << '\n';

    try {
        std::cout << "���⭮� (z1 / z2) = " << z1 / z2 << '\n';
    } catch (const std::exception& e) {
        std::cerr << "�訡�� �� �������: " << e.what() << '\n';
    }

    std::cout << "����殮��� z1 (conj(z1)) = " << z1.conjugate() << '\n';
    std::cout << "���������� z1 � 楫�� �⥯��� 3: z1^3 = " << z1.pow(3) << '\n';
    std::cout << "���������� z1 � ����⢥���� �⥯��� 2.5: z1^2.5 = " << z1.pow(2.5) << '\n';
    std::cout << "���������� z1 � ����⥫��� �⥯��� -1: z1^-1 = " << z1.pow(-1) << '\n';

    int n = 3;
    Complex* roots = Complex::roots(z1, n);
    std::cout << "��୨ " << n << "-� �⥯��� �� z1:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "��७� " << (i + 1) << " = " << roots[i] << '\n';
    }
    delete[] roots;

    std::cout << "�����ࠨ�᪠� �ଠ z1: " << z1.toAlgebraic() << '\n';
    std::cout << "�ਣ��������᪠� �ଠ z1: " << z1.toTrigonometric() << '\n';
    std::cout << "��ᯮ���樠�쭠� �ଠ z1: " << z1.toExponential() << std::endl;
}
