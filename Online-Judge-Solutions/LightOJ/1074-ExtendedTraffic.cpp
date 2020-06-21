/*
    Author : Simanta Deb Turja
*/
#include <bits/stdc++.h>
using namespace std;
 
#define Professor
 
using ll = long long;
using i64 = unsigned long long;
 
 
template< typename T1, typename T2, typename T3 > struct Pair {
    T1 first; T2 second; T3 third;
};
template< typename T1, typename T2, typename T3, typename T4 > struct Pair4 {
    T1 first; T2 second; T3 third; T4 fourth;
};
 
 
using ii = pair <int, int>;
using iii = Pair <int, int, int>;
using iiii = Pair4 <int, int, int, int>;
 
#define endl '\n'
#define all(x) x.begin(), x.end()
#define all_c(x, c) x.begin(), x.end(), c
 
 
const int N = (int)4e5 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const ll LLINF = (ll)1e15+1;
const int INF = (int)1e8;
const ll MOD = (ll)1e9 + 7;
 
 
vector <pair <int, int> > g[210];
int main() {
    int tc, kase = 1;
    cin >> tc;
    while (tc--) {
        auto Solve = [&]() {
            #ifdef __APPLE__
                //cout << "Started Running.....\n";
            #endif
            cout << "Case " << kase++ << ":\n";
            int n;
            cin >> n;
            vector <int> busyness(n + 1);
            for (int i = 1; i <= n; ++i) {
                cin >> busyness[i];
            }
            function <int(int, int)> cube_diff = [&](int x, int y) {
                return (y - x) * (y - x) * (y - x);
            };
            int m;
            cin >> m;
            for (int i = 0; i < m; ++i) {
                int u, v;
                cin >> u >> v;
                g[u].emplace_back(v, cube_diff(busyness[u], busyness[v]));
            }
            vector <int> dist(n + 1, INF);
            vector <bool> neg_cycle(n + 1, 0);
            dist[1] = 0;
            function <void(void)> bellmen_ford = [&](void) {
                for (int iter = 0; iter < n - 1; ++iter) {
                    for (int i = 1; i <= n; ++i) {
                        for (auto it : g[i]) {
                            if (dist[i] + it.second < dist[it.first]) {
                                dist[it.first] = it.second + dist[i];
                            }
                        }
                    }
                }
                for (int i = 1; i <= n; ++i) {
                    for (auto it : g[i]) {
                        if (dist[i] + it.second < dist[it.first]) {
                            dist[it.first] = dist[i] + it.second;
                            neg_cycle[it.first] = 1;
                        }
                    }
                }
            };
            bellmen_ford();
            int q;
            cin >> q;
            while (q--) {
                int dest;
                cin >> dest;
                if (neg_cycle[dest] || dist[dest] >= INF || dist[dest] < 3) {
                    cout << "?" << endl;
                } else {
                    cout << dist[dest] << endl;
                }
            }
            for (int i = 1; i <= n; ++i) g[i].clear();
        };
        Solve();
    }
    return 0;
}