#include <iostream>
int main() {
  int w = 0;
  std::cin >> w;
  std::cout << ((w >= 4 && w % 2 == 0) ? "YES" : "NO") << '\n';
  return 0;
}