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
const ll LLINF = numeric_limits<ll>::max();
const int INF = numeric_limits<int>::max();
const ll MOD = (ll)1e9 + 7;

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto Solve = [&]() {
        #ifdef __APPLE__
            cout << "Running\n";
        #endif
        int n;
        cin >> n;
        vector <int> h(n + 1), dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> h[i];
        }
        dp[1] = 0, dp[2] = abs(h[2] - h[1]);
        for (int i = 3; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2] + abs(h[i - 2] - h[i]));
        }
        cout << dp[n] << endl;

    };
    Solve();
    
    return 0;
}

