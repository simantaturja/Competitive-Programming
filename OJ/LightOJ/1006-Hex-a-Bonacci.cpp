#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (int)1e4 + 10;
const ll mod = (ll)10000007;

ll arr[7], dp[N + 7];
int n;

ll fn (int n) {
    if (n <= 5) return arr[n] % mod;
    if (dp[n] != -1) return dp[n] % mod;
    ll ret = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % mod;
    return dp[n] = ret;
}

int main() {
    int tc, kase = 1;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < 6; ++i) {
            scanf("%lld", &arr[i]);
        }
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %lld\n", kase++, fn(n) % mod);
    }
    return 0;
}