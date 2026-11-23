#include "complex.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>

// Унарный минус
Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

// Сравнение с учетом погрешности eps
bool Complex::operator==(const Complex& rhs) const noexcept {
  const double eps = 2 * std::numeric_limits<double>::epsilon();
  return std::abs(re - rhs.re) <= eps && std::abs(im - rhs.im) <= eps;
}

bool Complex::operator!=(const Complex& rhs) const noexcept { return !(*this == rhs); }

// Присваивающее сложение
Complex& Complex::operator+=(const Complex& rhs) noexcept {
  re += rhs.re;
  im += rhs.im;
  return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }

// Присваивающее вычитание
Complex& Complex::operator-=(const Complex& rhs) noexcept {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

// Присваивающее умножение
Complex& Complex::operator*=(const Complex& rhs) noexcept {
  double new_re = re * rhs.re - im * rhs.im;
  double new_im = re * rhs.im + im * rhs.re;
  re = new_re;
  im = new_im;
  return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
  re *= rhs;
  im *= rhs;
  return *this;
}

// Присваивающее деление
Complex& Complex::operator/=(const Complex& rhs) {
  double denom = rhs.re * rhs.re + rhs.im * rhs.im;
  if (denom == 0.0) {
    throw std::invalid_argument("Division by zero complex number");
  }
  double new_re = (re * rhs.re + im * rhs.im) / denom;
  double new_im = (im * rhs.re - re * rhs.im) / denom;
  re = new_re;
  im = new_im;
  return *this;
}
Complex& Complex::operator/=(const double rhs) {
  if (rhs == 0.0) {
    throw std::invalid_argument("Division by zero");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

// Ввод/вывод
std::ostream& Complex::write_to(std::ostream& ostrm) const noexcept {
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}

std::istream& Complex::read_from(std::istream& istrm) noexcept {
  char left, sep, right;
  if (istrm >> left >> re >> sep >> im >> right) {
    if (left != leftBrace || sep != separator || right != rightBrace) {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

// (+=, -=, *=, /=)
Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }