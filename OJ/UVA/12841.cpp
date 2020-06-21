#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 16);
const int inf = (1 << 22);
int res, cmp[200];
char rmp[200];
int n, m, target;
vector <int> adj[20], ans;
vector <char> nodes;
int dp[20][N];

int chk(int pos, int mask) {
    return mask&(1<<pos);
}
int Set(int pos, int mask) {
    return mask|(1<<pos);
}

int solve(int pos, int mask) {
    if ( pos == target ) {
        return (mask == res - 1);
    }
    if ( dp[pos][mask] != -1 ) return dp[pos][mask];
    int ret = 0;
    for ( int i = 0; i < adj[pos].size(); ++i ) {
        int u = adj[pos][i];
        if ( !chk(u, mask) ) {
            ret = solve(u, Set(u, mask));
            if ( ret ) break;
        }
    }
    return dp[pos][mask] = ret;
}
void gen(int pos, int mask) {
    if ( pos == target && mask == res - 1 ) return;
    for ( int i = 0; i < adj[pos].size(); ++i ) {
        int u = adj[pos][i];
        if ( !chk(u, mask) ) {
            int ret = solve(u, Set(u, mask));
            if ( ret == dp[pos][mask] ) {
                ans.push_back(u);
                gen(u, Set(u, mask));
                break;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    for ( int kase = 1; kase <= tc; ++kase ) {
        cin >> n >> m;
        for ( int i = 0; i < n; ++i ) {
            char u;
            cin >> u;
            nodes.push_back(u);
        }

        char src = nodes[0], des = nodes[n - 1];

        sort(nodes.begin(), nodes.end());

        for ( int i = 0; i < n; ++i ) {
            if ( cmp[nodes[i]] == 0 ) {
                cmp[nodes[i]] = i;
                rmp[i] = nodes[i];
            }
        }
        for ( int i = 1; i <= m; ++i ) {
            char u, v;
            cin >> u >> v;
            adj[cmp[u]].push_back(cmp[v]);
            adj[cmp[v]].push_back(cmp[u]);
        }

        target = cmp[des];
        res = (1 << n);

        for ( int i = 0; i < n; ++i ) {
            sort(adj[i].begin(), adj[i].end());
        }
        memset(dp, -1, sizeof(dp));
        int ret = solve(cmp[src], (1 << cmp[src]));
        if ( ret == 0 ) {
            cout << "Case " << kase << ": impossible\n";
        } else {
            cout << "Case " << kase << ": " << src;
            gen(cmp[src], 1 << cmp[src]);
            for ( int i = 0; i < ans.size(); ++i ) {
                cout << (char)rmp[ans[i]];
            }
            cout << '\n';
        }

        for ( int i = 0; i < n; ++i ) adj[i].clear();
        nodes.clear();
        memset(cmp, 0, sizeof(cmp));
        ans.clear();
    }
    return 0;
}
