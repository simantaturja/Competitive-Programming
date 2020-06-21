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


const int N = (int)5e5 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const ll LLINF = (ll)1e18+1;
const int INF = (int)1e9+1;
const ll MOD = (ll)1e9 + 7;

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }

vector < ii > g[N + 10];
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
        vector <int> t(n + 1);
        vector < ii > arr;
        for (int i = 1; i <= n; ++i) {
            cin >> t[i];
            arr.push_back({t[i], i});
        }
        sort(all(arr));
        for (int i = 0; i < m; ++i) {
            int u = edges[i].first, v = edges[i].second;
            g[u].push_back({t[v], v});
            g[v].push_back({t[u], u});
        }
        for (int i = 1; i <= n; ++i) {
            sort (all(g[i]));
        }
        vector <bool> visited(n + 1, 0);
        vector <int> d(n + 1, 0);
        vector <int> nodes;
        function <void(int)> bfs = [&](int src) {
            queue <int> q;
            q.push(src);
            d[src] = 1;
            visited[src] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                nodes.push_back(u);
                int sz = (int)g[u].size(), valid = 0, x = 0;
                for (int i = 0; i < sz; ++i) {
                    int v = g[u][i].second;
                    int w = g[u][i].first;
                    if (!visited[v]) {
                        if (!valid) {
                            valid = 1;
                            x = w;
                        }
                        if (x == w) {
                            q.push(v);
                            d[v] = d[u] + 1;
                            visited[v] = 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            int to = arr[i].first, v = arr[i].second;
            if (visited[v] || to > 1) continue;
            bfs(v);
        }
        bool valid_main = 1;
        for (int i = 1; i <= n; ++i) {
            if (d[i] != t[i]) {
                valid_main = 0;
                break;
            }
        }
        if (!valid_main) {
            cout << -1 << endl;
        } else {
            int sz = (int)nodes.size();
            for (int i = 0; i < sz; ++i) {
                cout << nodes[i] << ' ';
            }
            cout << endl;
        }
    };
    Solve();
    return 0;
}

