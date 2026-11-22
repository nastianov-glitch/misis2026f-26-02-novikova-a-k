#include <iostream>
#include <string>

int main() {
    // Заранее составляем таблицу очков для каждой клетки 10x10
    int points[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int a = i, b = 9 - i, c = j, d = 9 - j;
            int mn = a;
            if (b < mn) mn = b;
            if (c < mn) mn = c;
            if (d < mn) mn = d;
            points[i][j] = mn + 1;
        }
    }

    int t;
    std::cin >> t;
    while (t--) {
        int score = 0;
        for (int i = 0; i < 10; i++) {
            std::string row;
            std::cin >> row;
            for (int j = 0; j < 10; j++) {
                if (row[j] == 'X') {
                    score += points[i][j];
                }
            }
        }
        std::cout << score << "\n";
    }
    return 0;
}