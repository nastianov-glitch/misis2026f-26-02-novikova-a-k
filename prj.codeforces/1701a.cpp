#include <iostream>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int s = 0;
    for (int i = 0; i < 4; ++i) { int x = 0; std::cin >> x; s += x; }
    std::cout << ((0 == s) ? 0 : (4 == s ? 2 : 1)) << '\n';
  }
  return 0;
}