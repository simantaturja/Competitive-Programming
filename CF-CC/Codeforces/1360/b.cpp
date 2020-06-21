/*
    Author : Simanta Deb Turja
*/
#include <bits/stdc++.h>
using namespace std;
#define Professor
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

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }

void solve();

int main() {
    FASTIO;
    //#ifdef Professor
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector <int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int mn = (int)1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                mn = min(mn, abs(arr[i] - arr[j]));
            }
        }
        cout << mn << endl;
    }
    //#endif
    return 0;
}

void solve() {
}