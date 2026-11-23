#include <iostream>
#include <string>
int main() {
  int n = 0;
  std::string s;
  std::cin >> n >> s;
  int ans = 0, run = 0;
  for (char c : s) {
    if ('x' == c) { ++run; if (run >= 3) ++ans; }
    else run = 0;
  }
  std::cout << ans << '\n';
  return 0;
}