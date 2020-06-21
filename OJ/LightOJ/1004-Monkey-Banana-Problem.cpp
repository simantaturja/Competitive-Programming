#include <bits/stdc++.h>
using namespace std;
#define MAXN 101
typedef long long ll;
ll arr[2 * MAXN][MAXN];
ll dp[2 * MAXN][2 * MAXN];
int n;
 
int solve(int i, int j) {
    if(i == 2 * n + 2 || j == n + 1 || j == 0) return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    if (i < n ) dp[i][j] = max(solve(i + 1, j), solve(i + 1, j + 1)) + arr[i][j];
    else        dp[i][j] = max(solve(i + 1, j), solve(i + 1, j - 1)) + arr[i][j];
    return dp[i][j];
}
 
 
int main()
{
    int tc;
    scanf("%d", &tc);
    for(int kase = 1; kase <= tc; kase++) {
        scanf("%d", &n);
        memset(arr, 0, sizeof arr);
        memset(dp, -1, sizeof dp);
 
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                scanf("%lld", &arr[i][j]);
            }
        }
        for(int i = n + 1; i <= 2 * n - 1; i++) {
            for(int j = 1; j <= 2 * n - i; j++)
                scanf("%lld", &arr[i][j]);
        }
        
        printf("Case %d: %lld\n", kase, solve(1, 1));
 
    }
    return 0;
}