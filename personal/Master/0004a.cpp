

#include <iostream>

int main() {
  int w = 0; // вес арбуза
  std::cin >> w;
  if (0 == w % 2 && 2 < w) {
    // w предсатвимо в виде суммы двух отличных от нуля четных чисел
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}