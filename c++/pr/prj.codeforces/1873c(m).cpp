#include <iostream>
#include <string>
using namespace std;

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
    cin >> t;
    while (t--) {
        int score = 0;
        for (int i = 0; i < 10; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < 10; j++) {
                if (row[j] == 'X') {
                    score += points[i][j];
                }
            }
        }
        cout << score << "\n";
    }
    return 0;
}