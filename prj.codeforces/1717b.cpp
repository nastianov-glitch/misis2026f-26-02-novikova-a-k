#include <iostream>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0, k = 0, r = 0, c = 0;
    std::cin >> n >> k >> r >> c;
    const int key = (r + c) % k;   // X на диагоналях (i+j) % k == (r+c) % k
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        std::cout << (((i + j) % k == key) ? 'X' : '.');
      }
      std::cout << '\n';
    }
  }
  return 0;
}