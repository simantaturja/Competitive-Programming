/*
    Author : Simanta Deb Turja
*/
#include <bits/stdc++.h>
using namespace std;

#define Professor

using ll = long long;
using i64 = unsigned long long;

template <typename T> inline T Min (T a, T b, T c) { 
    return min(a, min(b, c)); 
}
template <typename T> inline T Min (T a, T b, T c, T d) { 
    return min(a, min(b, min(c, d))); 
}
template <typename T> inline T Max (T a, T b, T c) { 
    return max(a, max(b, c)); 
}
template <typename T> inline T Max (T a, T b, T c, T d) { 
    return max(a, max(b, max(c, d))); 
}

template <typename T> inline T Ceil(T a, T b) { 
    return ((a % b == 0) ? (a / b) : (a / b + 1)); 
} 
template <typename T> inline T Floor(T a, T b) { 
    return a / b; 
}

template <typename T> inline T Power (T a, T p) { 
    T res = 1, x = a; 
    while ( p ) { 
        if ( p & 1 ) res = ( res * x ); 
        x = ( x * x ); p >>= 1;
    }
    return res; 
}
template <typename T> inline T BigMod (T a,T p,T M) { 
    a %= M; T ret = (T)1; 
    while (p) { 
        if (p & 1) ret = (ret * a) % M; 
        a = (a * a) % M;  p = p >> 1;
    } 
    return ret;
}
template <typename T> inline T InverseMod (T a,T M) { 
    return BigMod (a, M - 2, M); 
}

template <typename T> inline T gcd ( T a, T b ) { 
    a = abs(a); b = abs(b); 
    while ( b ) { 
        a = a % b; swap ( a, b ); 
    } 
    return a;
}
template <typename T> inline T lcm(T x,T y) { 
    return (((x)/gcd((x),(y)))*(y)); 
}
template <typename T> inline T Reverse(T x) { 
    reverse(x.begin(), x.end()); return x; 
}

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
const ll LLINF = (ll)1e18+1;
const int INF = (int)1e9+1;
const ll MOD = (ll)1e9 + 7;

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto Solve = [&]() {
        #ifdef __APPLE__
            cout << "Started Running.....\n";
        #endif
        int h, w, k_max, sx, sy, ex, ey;
        cin >> h >> w >> k_max >> sx >> sy >> ex >> ey;
        --sx, --sy, --ex, --ey;
        vector <vector <char> > grid(h, vector <char> (w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }
        vector <vector <int> > dist(h, vector <int> (w, -1));
        function <bool(int, int)> isValid = [&](int x, int y) {
            return (x >= 0 && x < h && y >= 0 && y < w);
        };
        function <void(void)> bfs = [&](void) {
            dist[sx][sy] = 0;
            queue <ii> q;
            q.push({sx, sy});
            while (!q.empty()) {
                auto current = q.front();
                q.pop();
                int cx = current.first, cy = current.second;
                for (int i = 0; i < 4; ++i) {
                    for (int k = 1; k <= k_max; ++k) {
                        int nx = cx + (dx[i] * k);
                        int ny = cy + (dy[i] * k);
                        if (!isValid(nx, ny) || grid[nx][ny] == '@') break;
                        if (isValid(nx, ny) && grid[nx][ny] != '@') {
                            if (dist[nx][ny] == -1) {
                                dist[nx][ny] = dist[cx][cy] + 1;
                                q.push({nx, ny});
                            } else {
                                if (dist[nx][ny] >= dist[cx][cy] + 1) {
                                    dist[nx][ny] = dist[cx][cy] + 1;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        };
        bfs();
        if (dist[ex][ey] != -1) {
            cout << dist[ex][ey] << endl;
        } else {
            cout << "-1\n";
        }
    };
    Solve();
    return 0;
}

