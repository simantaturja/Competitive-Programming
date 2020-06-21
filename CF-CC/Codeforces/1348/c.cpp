/*
    Author : Simanta Deb Turja
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long i64;
template <typename T> inline T Min (T a, T b, T c) { return min(a, min(b, c)); }
template <typename T> inline T Min (T a, T b, T c, T d) { return min(a, min(b, min(c, d))); }
template <typename T> inline T Max (T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> inline T Max (T a, T b, T c, T d) { return max(a, max(b, max(c, d))); }
template <typename T> inline T Power (T a, T p) { T res = 1, x = a; while ( p ) { if ( p & 1 ) res = ( res * x ); x = ( x * x ); p >>= 1; } return res; }
template <typename T> inline T gcd ( T a, T b ) { a = abs(a); b = abs(b); while ( b ) { a = a % b; swap ( a, b ); } return a; }
template <typename T> inline T lcm(T x,T y) { return (((x)/gcd((x),(y)))*(y)); }
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

const int N = (int)1e5 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const ll inf = 2147383647;
const ll mod = (ll)1e9 + 7;

void solve();

int main() {
    FASTIO;
    //#ifdef __APPLE__
    int tc;
    cin >> tc;
    while (tc--) {
    //#endif
        int n, k;
        string s;
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        if (k == 1 || k == n) {
            if (k == 1) {
                cout << s << "\n";
            } else {
                cout << s[n - 1] << "\n";
            }
        } else {
            vector <string> ls(k), ps(k);
            for (int i = 0; i < k; ++i) {
                ls[i] += s[i];
                ps[i] += ls[i];
            }
            for (int i = k; i < n; ++i) {
                ls[0] += s[i];
                ps[i % k] += s[i];
            }
            sort(ls.begin(), ls.end());
            sort(ps.begin(), ps.end());
            string ans = min(ls[k - 1], ps[k - 1]);
            cout << ans << '\n';
        }
        
    //#ifdef __APPLE__
    }
    //#endif
    return 0;
}

void solve() {
    
}