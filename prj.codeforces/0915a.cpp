#include <iostream>
int main() {
  int n = 0, k = 0;
  std::cin >> n >> k;
  int ans = 1000;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    std::cin >> a;
    if (k % a == 0) ans = std::min(ans, k / a);
  }
  std::cout << ans << '\n';
  return 0;
}