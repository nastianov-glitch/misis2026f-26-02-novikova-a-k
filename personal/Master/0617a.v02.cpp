#include <iostream>

int main() {
  int x = 0;
  std::cin >> x;
  int n = x / 5;
  std::cout << ((0 == n % 5) ? n : n + 1) << std::endl;
}