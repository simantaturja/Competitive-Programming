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
    vector <ll> arr(32);
    arr[2] = 2;
    for (int i = 4; i <= 30; i += 2) {
        arr[i] = arr[i - 2] + Power(2LL, (ll)i / 2);
    }
    //#ifdef __APPLE__
    int tc;
    cin >> tc;
    while (tc--) {
    //#endif
        int n;
        cin >> n;
        cout << arr[n] << '\n'; 
    //#ifdef __APPLE__
    }
    //#endif
    return 0;
}

void solve() {
    
}