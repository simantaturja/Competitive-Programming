/*
    Author : Simanta Deb Turja
*/
#include <bits/stdc++.h>
using namespace std;

#define Professor

using ll = long long;
using i64 = unsigned long long;

template <typename T> inline T Min (T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> inline T Min (T a, T b, T c, T d) { return min(a, min(b, min(c, d))); }
template <typename T> inline T Max (T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> inline T Max (T a, T b, T c, T d) { return max(a, max(b, max(c, d))); }

template <typename T> inline T Ceil(T a, T b) { return ((a % b == 0) ? (a / b) : (a / b + 1)); } 
template <typename T> inline T Floor(T a, T b) { return a / b; }

template <typename T> inline T Power (T a, T p) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = ( res * x ); x = ( x * x ); p >>= 1;}return res; }
template <typename T> inline T BigMod (T a,T p,T M) { a %= M;T ret = 1; while (p) { if (p & 1) ret = (ret * a) % M; a = (a * a) % M; p = p >> 1; } return ret; }
template <typename T> inline T InverseMod (T a,T M) { return BigMod (a, M - 2, M); }

template <typename T> inline T gcd ( T a, T b ) { a = abs(a); b = abs(b); while ( b ) { a = a % b; swap ( a, b ); } return a; }
template <typename T> inline T lcm(T x,T y) { return (((x)/gcd((x),(y)))*(y)); }


#define endl '\n'
#define eb emplace_back

const int N = (int)4e5 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const ll LLINF = (ll)1e18+1;
const int INF = (int)1e9+1;
const ll MOD = (ll)1e9 + 7;

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto Solve = [&]() {
        #ifdef __APPLE__
            cout << "Running\n";
        #endif
        int n, m;
        cin >> n >> m;
        vector <int> graph[n + 1];
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        vector <int> dp(n + 1, -1);
        vector <bool> visited(n + 1, false);
        function <int(int)> dfs = [&] (int u) {
            visited[u] = 1;
            if (dp[u] != -1) return dp[u];
            int path_length = 0;
            for (int i = 0; i < (int)graph[u].size(); ++i) {
                path_length = max(path_length, dfs(graph[u][i]));
            }
            dp[u] = 1 + max(dp[u], path_length);
            return dp[u];
        };
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        int mx = -1;
        for (int i = 1; i <= n; ++i) {
            mx = max(mx, dp[i]);
        }
        cout << mx - 1 << endl;
    };
    Solve();
    
    return 0;
}

