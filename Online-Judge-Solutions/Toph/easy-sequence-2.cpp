#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = (int)1e5 + 2;

unordered_map <ull, ull> dp;

ull solve(ull x) {
    if ( x == 1 ) return 1;
    ull ret = dp[x];
    if ( ret != 0 ) return ret;
    if ( x % 2 == 0 ) {
        ull now = x / 2;
        ull temp = solve(now);
        ret += (temp * temp) + 1;
    } else {
        ull now = x / 2;
        ull temp = solve(now);
        ++now;
        temp *= solve(now);
        temp += 2;
        ret += temp;
    }
    return dp[x] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    for ( int kase = 1; kase <= tc; ++kase ) {
        ull x;
        cin >> x;
        cout << "Case " << kase << ": " << solve(x) << endl;
    }
    return 0;
}
