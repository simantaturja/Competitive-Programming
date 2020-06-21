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

template <typename T> inline T Ceil(T a, T b) { return (a % b == 0 ? a / b : a / b + 1); } 
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
const ll LLINF = numeric_limits<ll>::max();
const int INF = numeric_limits<int>::max();
const ll MOD = (ll)1e9 + 7;

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //#ifdef __APPLE__
    int tc;
    cin >> tc;
    while (tc--) {
        auto Solve = [&]() {
            #ifdef __APPLE__
                cout << "Running\n";
            #endif
            int h, c, t;
            cin >> h >> c >> t;
            if (h == t) {
                cout << "1\n";
            } else if (h - t == t - c) {
                cout << "2\n";
            } else {
                int iteration = 1010, lo = 0, hi = (int)1e6+10;
                int t1 = 0, temp = 0;
                while(iteration--) {
                    int mid = (lo + hi) >> 1;
                    t1 = 2 * mid + 1;
                    temp = ((t1 + 1) * h) / 2 + (t1 / 2);
                    if (temp < t) {
                        hi = mid;
                    } else {
                        lo = mid;
                    }
                }
                double ret = (((t1 + 3) * h) / 2 + ((t1 + 2) / 2) * c) / (double)(t1 + 2);
                if (abs(t - ret) < abs(t - temp)) {
                    temp = ret;
                    t1 += 2;
                }
                if (abs((((h + c)/2.0) - t) <= abs(temp - t))) {
                    cout << 2 << endl;
                } else {
                    cout << t1 << endl;
                }
            }
        };
        Solve();
    }
    //#endif
    return 0;
}

