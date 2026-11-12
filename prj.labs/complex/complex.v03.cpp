#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <exception>

const auto EPSILON = std::numeric_limits<double>::epsilon() * 3;

struct Complex
{
    Complex() = default;
    explicit Complex(const double r);
    Complex(const double re, const double im = 0);
    
    // Явно объявленный оператор присваивания (Rule of Three)
    Complex& operator=(const Complex& rhs);
 
    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);

    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs);

    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);

    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);
    
    double re = 0.0;
    double im = 0.0;

    Complex conj() const;

    std::ostream& writeTo(std::ostream& out) const;
    std::istream& readFrom(std::istream& in);
};

// --- Реализация конструкторов ---

Complex::Complex(const double r) : Complex(r, 0.0) {}

Complex::Complex(const double re, const double im) : re(re), im(im) {}

// --- Реализация оператора присваивания ---
Complex& Complex::operator=(const Complex& rhs)
{
    if (this != &rhs) // Защита от самоприсваивания (x = x)
    {
        re = rhs.re;
        im = rhs.im;
    }
    return *this;
}

// Арифметические операторы (дружественные функции - в struct все поля по умолчанию публичные, поэтому функции снаружи могут спокойно читать lhs.re и rhs.im. 

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}
Complex operator+(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re + rhs, lhs.im);
}
Complex operator+(const double lhs, const Complex& rhs)
{
    return Complex(rhs.re + lhs, rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex operator-(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re - rhs, lhs.im);
}
Complex operator-(const double lhs, const Complex& rhs)
{
    return Complex(lhs - rhs.re, -rhs.im); // Исправлено: im должен быть отрицательным
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im , lhs.re * rhs.im + rhs.re * lhs.im);
}
Complex operator*(const Complex& lhs, const double rhs)
{
    return Complex(lhs.re * rhs, lhs.im * rhs);
}
Complex operator*(const double lhs, const Complex& rhs)
{
    return Complex(rhs.re * lhs, rhs.im * lhs);
}

Complex operator/(const Complex& lhs, const double rhs)
{
    if (std::abs(rhs) < EPSILON)
        throw std::exception();

    return Complex(lhs.re / rhs, lhs.im / rhs);
}

Complex operator/(const double lhs, const Complex& rhs)
{
    if (std::abs(rhs.re) < EPSILON && std::abs(rhs.im) < EPSILON)
        throw std::exception();
    return (lhs * rhs.conj()) / (rhs.re * rhs.re + rhs.im * rhs.im);
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    if (std::abs(rhs.re) < EPSILON && std::abs(rhs.im) < EPSILON)
        throw std::exception();

    return Complex(lhs * rhs.conj()) / (rhs.re * rhs.re + rhs.im * rhs.im);
}

// Операторы сравнения 

bool Complex::operator==(const Complex& rhs) const
{
    return (rhs.re == re && rhs.im == im);
}

bool Complex::operator!=(const Complex& rhs) const
{
    return !(*this == rhs);
}

//Операторы присваивания с арифметикой (+=, -=, *=, /=)

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
} 
Complex& Complex::operator+=(const double rhs)
{
    re += rhs;
    return *this;
} 

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}
Complex& Complex::operator-=(const double rhs)
{
    re -= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double tmp_re = re;
    re = re * rhs.re - im * rhs.im;
    im = tmp_re * rhs.im + im * rhs.re; // Исправлено использование tmp_re
    return *this;
}
Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
    if (std::abs(rhs.re) < EPSILON && std::abs(rhs.im) < EPSILON)
        throw std::exception();

    double denum = rhs.re * rhs.re + rhs.im * rhs.im;
    double old_re = re; // Сохраняем старое значение re
    
    // Исправлены формулы деления
    re = (old_re * rhs.re + im * rhs.im) / denum;
    im = (im * rhs.re - old_re * rhs.im) / denum;

    return *this;
}
Complex& Complex::operator/=(const double rhs)
{
    if (std::abs(rhs) < EPSILON)
        throw std::exception();
    
    re = re / rhs;
    im = im / rhs;
    return *this;
}

//Вспомогательные методы 

Complex Complex::conj() const
{
    return Complex(re, -im);
} 

std::ostream& Complex::writeTo(std::ostream& out) const
{
    if (std::abs(im) < EPSILON)
        out << re;
    else if(im > 0)
        out << re << " + " << im << 'i';
    else
        out << re << " - " << -im << 'i';
    
    return out << "\n"; // Изменено на \n для красивого вывода
}

std::istream& Complex::readFrom(std::istream& in)
{
    double temp_re(0.0);
    char comma(0);
    double temp_im(0.0);
    char i(0);
    
    in >> temp_re >> comma >> temp_im >> i; 
    
    if (in.good())
    {
        if (i == 'i' && (comma == '+' || comma == '-'))
        {
            this->re = temp_re;
            this->im = (comma == '+') ? temp_im : -temp_im;
        }
        else
        {
            in.setstate(std::ios_base::failbit);
        }
    }
    return in;
}

// Глобальные операторы ввода/вывода 

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
    return z.writeTo(out);
}

std::istream& operator>>(std::istream& in, Complex& z)
{
    return z.readFrom(in);
}

int main()
{
    Complex a(2, 5);        
    Complex b(-3, 1);       
    Complex c;
    Complex d(8, 0);

    std::cout << "--- Исходные значения ---\n";
    std::cout << "A = " << a;
    std::cout << "B = " << b;
    std::cout << "C = " << c;
    std::cout << "D = " << d;

    std::cout << "\n--- Проверка арифметики с числами ---\n";
    std::cout << "a + 3 = " << a + 3;
    std::cout << "b - 2 = " << b - 2;
    std::cout << "c * 6.7 = " << c * 6.7;
    std::cout << "d / 2 = " << d / 2;

    std::cout << "\n--- Проверка операторов +=, -=, *=, /= ---\n";
    a += 8;     std::cout << "a += 8   -> " << a;
    b -= 2.9;   std::cout << "b -= 2.9 -> " << b;
    c *= 4;     std::cout << "c *= 4   -> " << c;
    d /= 1.61;  std::cout << "d /= 1.61-> " << d;

    std::cout << "\n--- Проверка арифметики с комплексными числами ---\n";
    a += b; std::cout << "a += b   -> " << a;
    a -= c; std::cout << "a -= c   -> " << a;
    a *= d; std::cout << "a *= d   -> " << a;
    
    try
    {
        a /= b; std::cout << "a /= b   -> " << a;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Ошибка: Деление на ноль!" << '\n';
    }

    // Присваивание =
    std::cout << "\n--- Проверка оператора присваивания (=) ---\n";
    
    Complex x(1.5, 2.5);
    Complex y(10, -4);
    Complex z; // z = {0, 0}

    std::cout << "До присваивания:\n";
    std::cout << "x = " << x;
    std::cout << "y = " << y;
    std::cout << "z = " << z;

    // Сама проверка
    z = x; 
    std::cout << "После 'z = x':\n";
    std::cout << "z = " << z; // Должно вывести 1.5 + 2.5i

    // Проверка цепочки
    Complex w;
    w = z = y; 
    std::cout << "После цепочки 'w = z = y':\n";
    std::cout << "z = " << z; // Должно стать 10 - 4i
    std::cout << "w = " << w; // Должно стать 10 - 4i

    // Проверка самоприсваивания
    x = x; 
    std::cout << "После самоприсваивания 'x = x':\n";
    std::cout << "x = " << x; // Должно остаться 1.5 + 2.5i

    std::cout << "\n--- Проверка ввода с клавиатуры ---\n";
    std::cout << "Введите комплексное число (например, 3+4i): ";
    Complex v;
    if (std::cin >> v) {
        std::cout << "Вы ввели: " << v;
        std::cout << "Результат v += v: " << (v += v);
    } else {
        std::cout << "Ошибка ввода!" << std::endl;
    }

    return 0;
}