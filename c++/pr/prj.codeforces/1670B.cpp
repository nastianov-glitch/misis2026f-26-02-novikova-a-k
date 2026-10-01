#include <string>
#include <iostream>
#include <set>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::string s;
        std::cin >> n >> s;
        int k;
        std::cin >> k;

        // Множество особых букв
        std::set<char> sp;
        for (int i = 0; i < k; ++i) {
            char c;
            std::cin >> c;
            sp.insert(c);
        }

        int ans = 0;          // ответ
        int last = -1;        // позиция прошлой особой буквы

        for (int i = 0; i < n; ++i) {
            if (sp.count(s[i])) {      // если буква особая
                // Расстояние между текущей и прошлой особой буквой (не включая их)
                ans = std::max(ans, i - last - 1);
                last = i;              // запоминаем позицию
            }
        }
        // Учитываем суффикс после последней особой буквы
        ans = std::max(ans, n - last - 1);

        std::cout << ans << "\n";
    }
    return 0;
}
