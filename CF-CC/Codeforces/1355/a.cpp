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
bool ok(ll n) {
    while (n != 0) {
        if (n % 10 == 0) {
            return 0;
        }
        n /= 10;
    }
    return 1;
}
ll getNumber(ll n) {
    ll mn = (ll)(1e18 + 2);
    ll mx = -(ll)(1e18 + 2);
    ll num = n;
    while (n != 0) {
        ll d = n % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        n /= 10;
    }
    return num + (mn * mx);
}
int main() {
    FASTIO;
    //#ifdef Professor
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << n << endl;
            continue;
        }
        vector <ll> ret;
        ret.push_back(n);
        ll temp = n;
        while (true) {
            temp = ret[(int)ret.size() - 1];
            if (!ok(temp)) {
                break;
            } else {
                ret.push_back(getNumber(temp));
            }
            if ((int)ret.size() >= k) break;
        }
        cout << ret[(int)ret.size() - 1] << endl;
    }
    //#endif
    return 0;
}

void solve() {
}