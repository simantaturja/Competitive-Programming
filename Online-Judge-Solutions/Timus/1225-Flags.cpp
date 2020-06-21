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

ll dp[50][3][3];
ll solve (int pos, int prev, int curr, int n) {
    if (pos == n) return 1LL;
    if (dp[pos][prev][curr] != -1) return dp[pos][prev][curr];
    ll ret = 0LL;
    if (curr == 0) {
        if (prev == 1) ret += solve(pos + 1, curr, 2, n);
        else if (prev == 2) ret += solve(pos + 1, curr, 1, n);
    } else {
        if (curr == 1) ret += solve(pos + 1, curr, 0, n) + solve(pos + 1, curr, 2, n);
        else if (curr == 2) ret += solve(pos + 1, curr, 0, n) + solve(pos + 1, curr, 1, n);
    }
    return dp[pos][prev][curr] = ret;
}

int main() {
    FASTIO;
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 1, 0, n) + solve(1, 2, 0, n) << endl;
    return 0;
}

