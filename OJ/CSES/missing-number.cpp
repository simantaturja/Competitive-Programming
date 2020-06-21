#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll sum = 0LL;
    for (int i = 0; i < n - 1; ++i) {
        ll x;
        cin >> x;
        sum += x;
    }
    ll total = (ll)(n) * (n + 1LL) / 2;
    cout << total - sum << endl;
    return 0;
}