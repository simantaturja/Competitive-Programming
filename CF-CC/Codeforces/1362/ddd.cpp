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
template <typename T> inline T Reverse(T x) { reverse(x.begin(), x.end()); return x; }

template< typename T1, typename T2, typename T3 > struct Pair { T1 first; T2 second; T3 third; };
template< typename T1, typename T2, typename T3, typename T4 > struct Pair4 { T1 first; T2 second; T3 third; T4 fourth; };


using ii = pair <int, int>;
using iii = Pair <int, int, int>;
using iiii = Pair4 <int, int, int, int>;

#define endl '\n'
#define all(x) x.begin(), x.end()
#define all_c(x, c) x.begin(), x.end(), c


const int N = (int)4e5 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const ll LLINF = (ll)1e18+1;
const int INF = (int)1e9+1;
const ll MOD = (ll)1e9 + 7;

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }

vector <int> blog[N + 10], g[N + 10];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto Solve = [&]() {
        #ifdef __APPLE__
            cout << "Running\n";
        #endif
        int n, m;
        cin >> n >> m;
        vector < ii > edges;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        vector <int> t(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
            blog[t[i]].push_back(i + 1);
        }
        sort( all(t) );
        for (int i = 0; i < m; ++i) {
            int u = edges[i].first, v = edges[i].second;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector <bool> visited(n + 1, 0);
        vector <int> nodes;
        for (int i = 0; i < n; ++i) {
            int sz = (int)blog[t[i]].size();
            for (int j = 0; j < sz; ++j) {
                if (t[i] == 1) {
                    visited[blog[t[i]][j]] = 1;
                    nodes.push_back(blog[t[i]][j]);
                    continue;
                }
                int u = blog[t[i]][j];
                bool valid = 1;
                for (int k = 0; k < g[u].size(); ++k) {
                    int vv = g[u][i];
                    if (visited[vv]) {
                        continue;
                    }
                    else {
                        valid = 0;
                        break;
                    }
                }
                if (!valid) {
                    cout << -1 << endl;
                    return;
                }
                nodes.push_back(u);
                visited[u] = 1;
            }
        }
    };
    Solve();
    
    return 0;
}

