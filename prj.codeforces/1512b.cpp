#include <iostream>
#include <string>
#include <utility>
#include <vector>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int n = 0;
    std::cin >> n;
    std::vector<std::string> g(n);
    for (auto& r : g) std::cin >> r;
    std::vector<std::pair<int, int>> star;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if ('*' == g[i][j]) star.push_back({ i, j });
    const auto [r1, c1] = star[0];
    const auto [r2, c2] = star[1];
    if (r1 == r2) {
      const int r = (r1 == 0) ? 1 : 0;
      g[r][c1] = g[r][c2] = '*';
    } else if (c1 == c2) {
      const int c = (c1 == 0) ? 1 : 0;
      g[r1][c] = g[r2][c] = '*';
    } else {
      g[r1][c2] = g[r2][c1] = '*';
    }
    for (const auto& r : g) std::cout << r << '\n';
  }
  return 0;
}