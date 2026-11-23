#include <iostream>
#include <string>
#include <vector>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    std::vector<std::string> g(8);
    for (auto& r : g) std::cin >> r;
    const int dr[4] = { -1, -1, 1, 1 };
    const int dc[4] = { -1, 1, -1, 1 };
    for (int r = 0; r < 8; ++r) {
      for (int c = 0; c < 8; ++c) {
        if ('#' != g[r][c]) continue;
        bool all = true;
        for (int k = 0; k < 4; ++k) {   // слон — единственная клетка,
          int rr = r + dr[k], cc = c + dc[k];  // у которой на всех 4 диагоналях есть '#'
          bool found = false;
          while (rr >= 0 && rr < 8 && cc >= 0 && cc < 8) {
            if ('#' == g[rr][cc]) { found = true; break; }
            rr += dr[k]; cc += dc[k];
          }
          if (!found) { all = false; break; }
        }
        if (all) std::cout << r + 1 << ' ' << c + 1 << '\n';
      }
    }
  }
  return 0;
}