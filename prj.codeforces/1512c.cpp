#include <iostream>
#include <string>
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    int a = 0, b = 0;
    std::string s;
    std::cin >> a >> b >> s;
    const int n = a + b;
    bool bad = false;
    for (int i = 0; i < n - 1 - i; ++i) {          // 1. фиксируем известные символы в парах
      const int j = n - 1 - i;
      if ('?' == s[i] && '?' == s[j]) continue;
      if ('?' == s[i]) s[i] = s[j];
      else if ('?' == s[j]) s[j] = s[i];
      if (s[i] != s[j]) { bad = true; break; }
    }
    if (!bad) {
      int cnt0 = 0, cnt1 = 0;
      for (char c : s) { if ('0' == c) ++cnt0; else if ('1' == c) ++cnt1; }
      int rem0 = a - cnt0, rem1 = b - cnt1;
      if (rem0 < 0 || rem1 < 0) bad = true;
      if (!bad && (n % 2 == 1) && ('?' == s[n / 2])) { // 2. средний символ
        if (rem0 % 2 == 1) { s[n / 2] = '0'; --rem0; }
        else if (rem1 % 2 == 1) { s[n / 2] = '1'; --rem1; }
        else bad = true;
      }
      if (!bad) {                                    // 3. заполняем оставшиеся пары
        for (int i = 0; i < n - 1 - i; ++i) {
          const int j = n - 1 - i;
          if ('?' == s[i]) {
            if (rem0 >= 2) { s[i] = s[j] = '0'; rem0 -= 2; }
            else if (rem1 >= 2) { s[i] = s[j] = '1'; rem1 -= 2; }
            else { bad = true; break; }
          }
        }
        if (0 != rem0 || 0 != rem1) bad = true;
      }
    }
    std::cout << (bad ? "-1" : s) << '\n';
  }
  return 0;
}