#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    multiset <ll> s;
    for (int i = 0; i < n; ++i) {
        ll num;
        cin >> num;
        s.insert(num);
    }
    int gondola_cnt = 0;
    while (true) {
        auto it = s.begin();
        if ((int)s.size() <= 1) break;
        ll rem = x - *it;
        auto pos = s.upper_bound(rem);
        if (pos != s.begin()) {
            pos--;
            if (pos == it) {
                s.erase(it);
            } else if ((*pos) + (*it) <= x) {
                s.erase(it);
                s.erase(pos);
            } else {
                s.erase(it);
            }
        } else {
            s.erase(it);
        }
        ++gondola_cnt;
    }
    gondola_cnt += (int)s.size();
    cout << gondola_cnt << endl;
    return 0;
}