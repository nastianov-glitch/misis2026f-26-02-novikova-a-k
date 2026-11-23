#include <iostream>
#include <vector>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n), b(n), tm(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
    for (auto& v : tm) std::cin >> v;
    long long dep = 0;
    for (int i = 0; i < n; ++i) {
      const long long prev = (i == 0) ? 0 : b[i - 1];
      const long long arr = dep + (a[i] - prev + tm[i]);
      if (i == n - 1) { std::cout << arr << '\n'; break; }
      dep = std::max<long long>(b[i], arr + (b[i] - a[i] + 1) / 2);
    }
  }
  return 0;
}