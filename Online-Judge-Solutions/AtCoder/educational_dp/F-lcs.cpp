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
        string s, t;
        cin >> s >> t;
        int len_s = (int)s.length(), len_t = (int)t.length();
        s = " " + s;
        t = " " + t;
        vector <vector <int> > dp(len_s + 1, vector <int> (len_t + 1, 0));
        vector <vector <int> > dp_dir(len_s + 1, vector <int> (len_t + 1, 0));
        for (int i = 1; i <= len_s; ++i) {
            for (int j = 1; j <= len_t; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    dp_dir[i][j] = 3;
                } else {
                    if (dp[i - 1][j] >= dp[i][j - 1]) {
                        dp[i][j] = dp[i - 1][j];
                        dp_dir[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i][j - 1];
                        dp_dir[i][j] = 2;
                    }
                }
            }
        }
        string ans = "";
        function <void(int, int)> print_result = [&](int i, int j) {
            if (i == 0 || j == 0) return;
            if (dp_dir[i][j] == 3) {
                ans += s[i];
                print_result(i - 1, j - 1);
            } else {
                if (dp_dir[i][j] == 2) {
                    print_result(i, j - 1);
                } else {
                    print_result(i - 1, j);
                }
            }
            return;
        };
        print_result(len_s, len_t);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    };
    Solve();
    
    return 0;
}

