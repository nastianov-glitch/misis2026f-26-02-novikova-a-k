#include <cstdlib>
#include <iostream>
int main() {
  int x = 0, r = 0, c = 0;
  for (int i = 1; i <= 5; ++i) {
    for (int j = 1; j <= 5; ++j) {
      std::cin >> x;
      if (1 == x) { r = i; c = j; }
    }
  }
  std::cout << std::abs(r - 3) + std::abs(c - 3) << '\n';
  return 0;
}