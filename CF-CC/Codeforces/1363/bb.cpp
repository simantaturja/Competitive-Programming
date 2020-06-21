#include <bits/stdc++.h>
 
#define For(i, a, b) for(ll i = a; i <= b; i++)
#define Fod(i, a, b) for(ll i = a; i >= b; i--)
#define X first
#define Y second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
const ll N = 1e4 + 10;
 
ll t, tong[N];
string s;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >>t;
    For(z, 1, t) {
        cin >>s;
        ll n = s.length(); s = " " + s;
        For(i, 1, n) tong[i] = tong[i-1] + (s[i] == '1');
        ll kq = min(tong[n], n - tong[n]);
        For(i, 1, n) kq = min(kq, i - tong[i] + tong[n] - tong[i]);
        Fod(i, n, 1) kq = min(kq, (n - i + 1) - (tong[n] - tong[i-1]) + tong[i-1]);
        cout <<kq <<'\n';
    }
}
