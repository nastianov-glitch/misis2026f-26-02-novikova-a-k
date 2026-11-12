#include <cmath>
#include <iostream>

int main() {
  int t = 0;
  std::cin >> t;
  for (; 0 < t; t -= 1) {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    int d = std::max(a, b) - std::min(a, b);
    if (d % 2 == 0) {
      d /= 2;
    } else {
      d = d / 2 + 1;
    }
    int n = d / c;
    if (d % c != 0) {
      n += 1;
    }
    std::cout << n << std::endl;
  }
}