#include <bits/stdc++.h>
using namespace std;
const int N = 410;
map <string, int> mp;
vector <int> adj[N + 7];
int n, dp[N + 7][2];
void solve(int u) {
    dp[u][1] = 1;
    for ( int i = 0; i < adj[u].size(); ++i ) {
        solve(adj[u][i]);
        dp[u][1] += dp[adj[u][i]][0];
        dp[u][0] += max(dp[adj[u][i]][0], dp[adj[u][i]][1]);
    }
}
void reset() {
    for ( int i = 1; i <= n; ++i ) {
        adj[i].clear();
    }
    mp.clear();
}
int main() {
    while( scanf("%d", &n) && n != 0 ) {
        string s;
        cin >> s;
        int indx = 0;
        mp[s] = ++indx;
        memset(dp, 0, sizeof(dp));
        for ( int i = 0; i < n - 1; ++i ) {
            string s1, s2;
            cin >> s1 >> s2;
            int u, v;
            if ( mp[s1] == 0 ) {
                mp[s1] = ++indx;
                u = indx;
            } else if ( mp[s1] != 0 ) {
                u = mp[s1];
            }
            if ( mp[s2] == 0 ) {
                mp[s2] = ++indx;
                v = indx;
            } else if ( mp[s2] != 0 ) {
                v = mp[s2];
            }
            adj[v].push_back(u);
        }
        solve(1);
        int ans = max(dp[1][1], dp[1][0]);
        if ( n == 1 ) {
            printf("%d Yes\n", ans);
        } else if ( n == 2 ) {
            printf("%d No\n", ans);
        } else {
            int notUniq = 0;
            for ( int i = 1; i <= n; ++i ) {
                for ( int j = 0; j < adj[i].size(); ++j ) {
                    if ( dp[i][0] == dp[i][1] && dp[adj[i][j]][0] == dp[adj[i][j]][1] ) {
                        notUniq = 1;
                        break;
                    }
                }
                if ( notUniq ) break;
            }
            if ( notUniq == 1 ) {
                printf("%d No\n", ans);
            } else {
                printf("%d Yes\n", ans);
            }
        }
        reset();
    }
    return 0;
}
