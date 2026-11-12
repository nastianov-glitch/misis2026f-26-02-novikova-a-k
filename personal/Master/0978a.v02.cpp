#include <iostream>
#include <vector>
 
int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> a(n, 0);
  for (int i = 0; i < n; i += 1) {
    std::cin >> a[i];
  }
  for (int i = a.size() - 1; 0 <= i; i -= 1) {
    const int v_curr = a[i];
    for (int j = 0; v_curr && j < i; j += 1) {
      if (v_curr == a[j]) {
        a[j] = 0;
        n -= 1;
      }
    }
  }
  std::cout << n << '\n';
  for (int i = 0; i < a.size(); i += 1) {
    if (a[i]) {
      std::cout << a[i] << ' ';
    }
  }
  return 0;
}