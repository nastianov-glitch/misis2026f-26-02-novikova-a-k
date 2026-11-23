#include <iostream>
#include <string>
int main() {
  int n = 0;
  std::string s;
  std::cin >> n >> s;
  int x = 0, y = 0, last = 0, ans = 0;
  for (char c : s) {
    if ('R' == c) ++x; else ++y;
    const int d = x - y;
    if (0 != d) {
      const int sgn = d > 0 ? 1 : -1;
      if (0 != last && sgn != last) ++ans;
      last = sgn;
    }
  }
  std::cout << ans << '\n';
  return 0;
}