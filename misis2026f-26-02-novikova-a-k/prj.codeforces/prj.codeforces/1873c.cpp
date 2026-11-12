#include <iostream>
#include <string>
#include <algorithm>


int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int score = 0;
        for (int i = 0; i < 10; i++) {
            std::string row;
            std::cin >> row;
            for (int j = 0; j < 10; j++) {
                if (row[j] == 'X') {
                    int dTop = i;
                    int dBottom = 9 - i;
                    int dLeft = j;
                    int dRight = 9 - j;
                     //score += min(min(dTop, dBottom), min(dLeft, dRight)) + 1;
                }
            }
        }
        std::cout << score << "\n";
    }
    return 0;
}