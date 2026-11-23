#include <iostream>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    long long n = 0, m = 0, sx = 0, sy = 0, d = 0;
    std::cin >> n >> m >> sx >> sy >> d;
    // маршрут вдоль верхней строки + правого столбца
    const bool route_top_right = (sx - 1 > d) && (m - sy > d);
    // маршрут вдоль левого столбца + нижней строки
    const bool route_left_bottom = (sy - 1 > d) && (n - sx > d);
    std::cout << ((route_top_right || route_left_bottom) ? n + m - 2 : -1) << '\n';
  }
  return 0;
}