#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;

int len[70], n, dp[70][N + 2], t;

int solve(int pos, int sum) {
    if ( sum == 0 ) return 0;
    if ( pos == n ) {
        if ( sum == 0 ) return 0;
        return -N;
    }
    int ret = dp[pos][sum];
    if ( ret != -1 ) return dp[pos][sum];
    if ( sum - len[pos] >= 0 ) {
        ret = max(ret, solve(pos + 1, sum - len[pos]) + 1);
    }
    ret = max(ret, solve(pos + 1, sum));
    return dp[pos][sum] = ret;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for ( int kase = 1; kase <= tc; ++kase ) {
        scanf("%d %d", &n, &t);
        for ( int i = 0; i < n; ++i ) {
            scanf("%d", &len[i]);
        }
        if ( t >= N ) {
            int sum = 0;
            for ( int i = 0; i < n; ++i ) {
                sum += len[i];
            }
            printf("Case %d: %d %d\n", kase, n, sum + 678);
        } else {
            memset(dp, -1, sizeof(dp));
            int ans = 0;
            for ( int i = 0; i < t; ++i ) {
                int temp = solve(0, i);
                ans = max(ans, temp);
            }
            int mx = 0;
            for ( int i = 0; i < n; ++i ) {
                for ( int j = t - 1; j >= 0; --j ) {
                    if ( dp[i][j] == ans ) {
                        mx = max(mx, j);
                        break;
                    }
                }
            }
            printf("Case %d: %d %d\n", kase, ans + 1, mx + 678);
        }
    }
    return 0;
}
