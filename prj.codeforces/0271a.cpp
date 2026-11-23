#include <iostream>
bool distinct_digits(int y) {
  int d[4] = {};
  for (int i = 0; i < 4; ++i) { d[i] = y % 10; y /= 10; }
  for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j)
      if (d[i] == d[j]) return false;
  return true;
}
int main() {
  int y = 0;
  std::cin >> y;
  while (!distinct_digits(++y)) {}
  std::cout << y << '\n';
  return 0;
}