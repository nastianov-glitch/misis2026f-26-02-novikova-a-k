#include <iostream>
#include <string>
#include <vector>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<std::string> g(n);
    for (auto& r : g) std::cin >> r;
    int r0 = n, c0 = m;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if ('R' == g[i][j]) {
          if (i < r0) r0 = i;   // верхняя строка с роботом
          if (j < c0) c0 = j;   // левый столбец с роботом
        }
    std::cout << (('R' == g[r0][c0]) ? "YES" : "NO") << '\n';
  }
  return 0;
}