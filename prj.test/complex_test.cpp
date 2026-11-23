#include <complex/complex.hpp>
#include <iostream>
#include <stdexcept> 

void check_contracts() {
  try {
    std::cout << "try divide by zero -> ";
    Complex z;
    z /= 0;
    std::cout << "nothing happens (trouble)\n";
  }
  catch (const std::invalid_argument& ex) {
    std::cout << "exception caught, msg - " << ex.what() << "\n";
  }
}

int main() {
  // Тест сравнения
  Complex a(1.0, 2.0);
  Complex b(1.0, 2.0);
  if (a == b) std::cout << "a == b: OK\n";
  else std::cout << "a == b: FAIL\n";

  // Тест арифметики
  Complex c = a + b;
  std::cout << "a + b = " << c << "\n";
  
  check_contracts();
  return 0;
}