#include <iostream>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0;
    std::cin >> n;
    int prev = 0, h = 1;
    bool has_prev = false, dead = false;
    for (int i = 0; i < n; ++i) {
      int a = 0;
      std::cin >> a;
      if (dead) continue;
      if (1 == a) {
        h += (has_prev && 1 == prev) ? 5 : 1;
      } else if (has_prev && 0 == prev) {
        dead = true;
      }
      prev = a;
      has_prev = true;
    }
    std::cout << (dead ? -1 : h) << '\n';
  }
  return 0;
}