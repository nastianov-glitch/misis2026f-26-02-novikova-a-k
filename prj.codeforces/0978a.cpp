#include <iostream>
#include <set>
#include <vector>
int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& v : a) std::cin >> v;
  std::set<int> seen;
  std::vector<int> res;
  for (int i = n - 1; i >= 0; --i) {
    if (seen.insert(a[i]).second) res.push_back(a[i]);
  }
  std::cout << res.size() << '\n';
  for (auto it = res.rbegin(); it != res.rend(); ++it) std::cout << *it << ' ';
  std::cout << '\n';
  return 0;
}