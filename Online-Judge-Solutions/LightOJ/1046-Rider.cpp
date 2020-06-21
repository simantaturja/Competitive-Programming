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

// Knight Moves
// (x+1, y+2), (x+1, y-2), (x+2, y+1), (x+2, y-1), (x-1, y+2), (x-1, y-2), (x-2, y+1), (x-2, y-1)

int dx[] = {+1, +1, +2, +2, -1, -1, -2, -2};
int dy[] = {+2, -2, +1, -1, +2, -2, +1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc, kase = 1;
    cin >> tc;
    while (tc--) {
        auto Solve = [&]() {
            #ifdef __APPLE__
                cout << "Started Running.....\n";
            #endif
            int n, m; //n = rows, m = columns
            cin >> n >> m;
            vector <vector <char> > grid(n, vector <char> (m));
            int total_rider = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cin >> grid[i][j];
                    if (grid[i][j] != '.') {
                        ++total_rider;
                    }
                }
            }
            vector <vector <vector <int> > > dist(110, vector <vector <int> > (110, vector <int> (110, -1)));
            function <bool(int, int)> isValid = [&](int x, int y) {
                return (x >= 0 && x < n && y >= 0 && y < m);
            };
            function <void(int, int, int, int)> bfs = [&](int rider, int sx, int sy, int k_max) {
                queue <ii> q;
                q.push({sx, sy});
                dist[rider][sx][sy] = 0;
                while (!q.empty()) {
                    auto current = q.front();
                    q.pop();
                    int cx = current.first, cy = current.second;
                    for (int i = 0; i < 8; ++i) {
                        for (int k = 1; k <= k_max; ++k) {
                            int nx = cx + (dx[i] * k);
                            int ny = cy + (dy[i] * k);
                            if (k % 2 == 0) {
                                if (dy[i] < 0) --ny;
                                else ++ny;
                            }
                            if (isValid(nx, ny)) {
                                if (dist[rider][nx][ny] == -1) {
                                    q.push({nx, ny});
                                    dist[rider][nx][ny] = dist[rider][cx][cy] + 1;
                                } else if (dist[rider][nx][ny] != -1 && dist[rider][nx][ny] >= dist[rider][cx][cy] + 1) {
                                    dist[rider][nx][ny] = dist[rider][cx][cy] + 1;
                                }
                            }
                        }
                    }
                }
            };
            int rider_num = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] != '.') {
                        bfs(rider_num++, i, j, (int)(grid[i][j] - '0'));
                    }
                }
            }
            int minimum_moves = (int)1e9;
            int moves = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    moves = 0;
                    for (int rider_num = 0; rider_num < total_rider; ++rider_num) {
                        moves += dist[rider_num][i][j];
                    }
                    minimum_moves = min(minimum_moves, moves);
                }
            }
            cout << "Case " << kase++ << ": " << minimum_moves << endl;
        };
        Solve();
    }
    return 0;
}

