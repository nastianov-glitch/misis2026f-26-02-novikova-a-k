#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <complex/complex.hpp>

TEST_CASE("[complex] - ctor and equality") {
  Complex a(1.0, 2.0);
  Complex b(1.0, 2.0);
  CHECK(a == b);
  CHECK_FALSE(a != b);
  Complex c(1.0 + 1e-10, 2.0);
  CHECK(a == c); // сравнение с учётом eps
}

TEST_CASE("[complex] - arithmetic") {
  Complex a(1.0, 2.0);
  Complex b(3.0, -1.0);
  CHECK((a + b) == Complex(4.0, 1.0));
  CHECK((a - b) == Complex(-2.0, 3.0));
  CHECK((a * b) == Complex(5.0, 5.0));
  CHECK((a / b) == Complex(0.1, 0.7));
  CHECK((a + 1.0) == Complex(2.0, 2.0));
  CHECK((1.0 + a) == Complex(2.0, 2.0));
  CHECK((2.0 * a) == Complex(2.0, 4.0));
}

TEST_CASE("[complex] - division by zero throws") {
  Complex z(1.0, 2.0);
  CHECK_THROWS(z / 0.0);
  CHECK_THROWS(z /= 0.0);
  CHECK_THROWS(z / Complex(0.0, 0.0));
}

TEST_CASE("[complex] - unary minus") {
  Complex z(1.5, -2.5);
  CHECK(-z == Complex(-1.5, 2.5));
}