#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        vector <int> arr(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        int mina = 0, raju = 0, ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                raju += arr[i];
            } else {
                mina += arr[i];
            }
            if (mina >= k) {
                ans = 1;
                break;
            }
            if (raju >= k) {
                ans = 2;
                break;
            }
        }
        if (ans == 0) {
            cout << "Mithu Win\n";
        } else if (ans == 1) {
            cout << "Mina Win\n";
        } else {
            cout << "Raju Win\n";
        }
    }
    return 0;
}