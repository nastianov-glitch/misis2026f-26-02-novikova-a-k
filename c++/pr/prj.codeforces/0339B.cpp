#include <iostream>


int main() {
    int n, m;
    std::cin >> n >> m;

    long long total = 0;   // общее время (может быть большим)
    int current = 1;       // текущий дом, начинаем с 1

    for (int i = 0; i < m; i++) {
        int a;
        std::cin >> a;
        if (a >= current) {
            total += a - current;          // идём вперёд по кольцу
        } else {
            total += n - current + a;      // идём через "ноль"
        }
        current = a;
    }

    std:: cout << total << "\n";
    return 0;
}