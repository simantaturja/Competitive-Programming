#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //preCalculate();
    int q;
    cin >> q;
    ll lmt = (ll)pow(2, 63);
    vector <ll> v;
    v.push_back(2LL);
    for (ll i = 1; ; ++i) {
        ll result = (ll)4LL * v[i-1] + 2LL;
        if (result >= 0 && result <= lmt) {
            v.push_back(result);
        } else break;
    }
    while(q--) {
        ll l, r;
        cin >> l >> r;
        double total = (r - l + 1.0);
        double cnt = 0.0;
        for (int i = 0; i < (int)v.size(); ++i) {
            if (v[i] >= l && v[i] <= r) ++cnt;
        }
        printf("%0.9lf\n", cnt / total);
    }
    return 0;
}