#include "rational.hpp"
#include <numeric>
#include <stdexcept>
#include <iostream>

// Вспомогательная функция для GCD (чтобы не тащить <numeric> в hpp)
static std::int32_t gcd(std::int32_t a, std::int32_t b) {
  a = std::abs(a);
  b = std::abs(b);
  while (b != 0) {
    std::int32_t t = b;
    b = a % b;
    a = t;
  }
  return a;
}

Rational::Rational(const std::int32_t num, const std::int32_t den)
  : num_(num), den_(den) {
  if (0 == den_) {
    throw std::invalid_argument("Zero denominator in Rational ctor");
  }
  normalize();
}

void Rational::normalize() noexcept {
  if (num_ == 0) {
    den_ = 1;
    return;
  }
  std::int32_t g = gcd(num_, den_);
  num_ /= g;
  den_ /= g;
  if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }
}

// Сравнения
bool Rational::operator==(const Rational& rhs) const noexcept {
  return num_ == rhs.num_ && den_ == rhs.den_;
}
bool Rational::operator!=(const Rational& rhs) const noexcept { return !(*this == rhs); }
bool Rational::operator<(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ < rhs.num_ * den_;
}
bool Rational::operator<=(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ <= rhs.num_ * den_;
}
bool Rational::operator>(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ > rhs.num_ * den_;
}
bool Rational::operator>=(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ >= rhs.num_ * den_;
}

// Арифметика
Rational& Rational::operator+=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ + rhs.num_ * den_;
  den_ = den_ * rhs.den_;
  normalize();
  return *this;
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ - rhs.num_ * den_;
  den_ = den_ * rhs.den_;
  normalize();
  return *this;
}
Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  normalize();
  return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.num_ == 0) {
    throw std::invalid_argument("Division by zero");
  }
  num_ *= rhs.den_;
  den_ *= rhs.num_;
  normalize();
  return *this;
}

Rational& Rational::operator+=(const int32_t rhs) noexcept { return operator+=(Rational(rhs)); }
Rational& Rational::operator-=(const int32_t rhs) noexcept { return operator-=(Rational(rhs)); }
Rational& Rational::operator*=(const int32_t rhs) noexcept { return operator*=(Rational(rhs)); }
Rational& Rational::operator/=(const int32_t rhs) { return operator/=(Rational(rhs)); }

// Ввод/вывод
std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
  return rhs.write_to(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
  return rhs.read_from(istrm);
}

std::ostream& Rational::write_to(std::ostream& ostrm) const noexcept {
  ostrm << num_ << "/" << den_;
  return ostrm;
}

std::istream& Rational::read_from(std::istream& istrm) noexcept {
  char sep;
  std::int32_t n, d;
  if (istrm >> n >> sep >> d) {
    if (sep != '/') {
      istrm.setstate(std::ios_base::failbit);
    } else if (d == 0) {
      istrm.setstate(std::ios_base::failbit);
    } else {
      *this = Rational(n, d);
    }
  }
  return istrm;
}

// Глобальные операторы
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational(lhs) *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational(lhs) /= rhs; }

Rational operator+(const Rational& lhs, const int32_t rhs) noexcept { return Rational(lhs) += rhs; }
Rational operator-(const Rational& lhs, const int32_t rhs) noexcept { return Rational(lhs) -= rhs; }
Rational operator*(const Rational& lhs, const int32_t rhs) noexcept { return Rational(lhs) *= rhs; }
Rational operator/(const Rational& lhs, const int32_t rhs) { return Rational(lhs) /= rhs; }

Rational operator+(const int32_t lhs, const Rational& rhs) noexcept { return Rational(lhs) += rhs; }
Rational operator-(const int32_t lhs, const Rational& rhs) noexcept { return Rational(lhs) -= rhs; }
Rational operator*(const int32_t lhs, const Rational& rhs) noexcept { return Rational(lhs) *= rhs; }
Rational operator/(const int32_t lhs, const Rational& rhs) { return Rational(lhs) /= rhs; }