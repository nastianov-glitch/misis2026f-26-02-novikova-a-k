#include <complex/complex.hpp>

#include <iostream>

void check_contracts() {
  try {
    std::cout << "try divide by zero -> ";
    Complex z;
    z /= 0;
    std::cout << "nothing happens (trouble)";
  }
  catch (const std::invalid_argument& ex) {
    std::cout << "exception caught, msg - " << ex.what();
  }
}

int main() {
  Complex z0;
  check_contracts();
  return 0;
}
