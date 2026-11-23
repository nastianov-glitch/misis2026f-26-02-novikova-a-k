#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <complex/complex.hpp>
#include <sstream>

TEST_CASE("[complex_io] - write_to format {re,im}") {
  std::ostringstream oss;
  oss << Complex(1.5, -2.5);
  CHECK(oss.str() == "{1.5,-2.5}");
}

TEST_CASE("[complex_io] - read_from valid input") {
  std::istringstream iss("{3.5,-1.25}");
  Complex z;
  iss >> z;
  CHECK_FALSE(iss.fail());
  CHECK(z == Complex(3.5, -1.25));
}

TEST_CASE("[complex_io] - read_from invalid input sets failbit") {
  std::istringstream iss1("3.5,-1.25"); // нет скобок
  Complex z(9, 9);
  iss1 >> z;
  CHECK(iss1.fail());

  std::istringstream iss2("{1;2}"); // неверный разделитель
  iss2 >> z;
  CHECK(iss2.fail());
}