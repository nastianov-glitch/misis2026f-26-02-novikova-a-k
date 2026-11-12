#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        // col[i] = 0 (неизвестно), 1 (ноль), 2 (единица)
        vector<int> col(k, 0);
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') continue;
            int idx = i % k;
            int val = (s[i] == '0') ? 1 : 2;

            if (col[idx] == 0) col[idx] = val;
            else if (col[idx] != val) { ok = false; break; }
        }

        if (!ok) { cout << "NO\n"; continue; }

        int cnt0 = 0, cnt1 = 0, cntQ = 0;
        for (int i = 0; i < k; i++) {
            if (col[i] == 1) cnt0++;
            else if (col[i] == 2) cnt1++;
            else cntQ++;
        }

        int half = k / 2;
        if (cnt0 <= half && cnt1 <= half &&
            cnt0 + cntQ >= half && cnt1 + cntQ >= half)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}