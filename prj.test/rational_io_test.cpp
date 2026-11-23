#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <rational/rational.hpp>
#include <sstream>

TEST_CASE("[rational_io] - write_to format num/den") {
  std::ostringstream oss;
  oss << Rational(3, 2);
  CHECK(oss.str() == "3/2");
}

TEST_CASE("[rational_io] - read_from valid input normalizes") {
  std::istringstream iss("6/8");
  Rational r;
  iss >> r;
  CHECK_FALSE(iss.fail());
  CHECK(r == Rational(3, 4));
}

TEST_CASE("[rational_io] - read_from zero denominator sets failbit") {
  std::istringstream iss("3/0");
  Rational r;
  iss >> r;
  CHECK(iss.fail());
}

TEST_CASE("[rational_io] - read_from wrong separator sets failbit") {
  std::istringstream iss("3a2");
  Rational r;
  iss >> r;
  CHECK(iss.fail());
}