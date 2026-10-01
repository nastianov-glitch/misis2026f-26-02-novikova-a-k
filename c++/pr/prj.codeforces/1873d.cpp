#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;

        int ops = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == 'B') {
                ops++;        // нужна операция
                i += k;       // стираем k подряд идущих ячеек
            } else {
                i++;          // белая — идём дальше
            }
        }
        std::cout << ops << "\n";
    }
    return 0;
}