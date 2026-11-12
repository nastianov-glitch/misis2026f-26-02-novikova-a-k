#include <iostream>

int main() {
  int w = 0; // вес арбуза
  std::cin >> w;
  std::cout << (0 == w % 2 && 2 < w ? "YES\n" : "NO\n");
}