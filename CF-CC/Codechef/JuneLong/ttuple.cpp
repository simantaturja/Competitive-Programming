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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        auto Solve = [&]() {
            #ifdef __APPLE__
                cout << "Running\n";
            #endif
            vector <ll> a, b;
            for (int i = 0; i < 3; ++i) {
                ll x;
                cin >> x;
                a.push_back(x);
            }
            for (int i = 0; i < 3; ++i) {
                ll x;
                cin >> x;
                b.push_back(x);
            }
            set < pair <ll, ll> > arr;
            for (int i = 0; i < 3; ++i) {
                arr.insert({a[i], b[i]});
            }
            
            // filtering Values (if a[i] == b[i] we can discard both of the values)
            vector <ll> ax, bx;
            for (auto x : arr) {
                if (x.second == x.first) continue;
                else {
                    ax.push_back(x.first);
                    bx.push_back(x.second);
                }
            }
            int n = (int)ax.size();
            if (n == 0) {
                cout << 0 << endl;
                return;
            }
            a.clear(), b.clear();
            for (int i = 0; i < n; ++i) {
                a.push_back(ax[i]);
                b.push_back(bx[i]);
            }
            vector <ll> diff(n), mult(n);
            // Try with moves = 1
            for (int i = 0; i < n; ++i) {
                diff[i] = bx[i] - ax[i];
                if (ax[i] != 0 && bx[i] % ax[i] == 0) {
                    mult[i] = bx[i] / ax[i];
                } else {
                    mult[i] = -1;
                }
            }
            bool valid = 1;
            for (int i = 1; i < n; ++i) {
                if (diff[i - 1] == diff[i]) continue;
                else {
                    valid = 0;
                    break;
                }
            }
            
            if (!valid) {
                valid = 1;
                for (int i = 1; i < n; ++i) {
                    if (mult[i] == -1) {
                        valid = 0;
                        break;
                    }
                    if (mult[i - 1] == mult[i]) continue;
                    else {
                        valid = 0;
                        break;
                    }
                }
            }
            if (valid) {
                cout << "1\n";
                return;
            }

            //Try with Moves = 2
            mult.clear(), diff.clear();
            ll mnMult = LLINF, mnDiff = LLINF;
            for (int i = 0; i < n; ++i) {
                if (a[i] != 0) mult.push_back(b[i] / a[i]);
                else mult.push_back(1LL);
                diff.push_back(b[i] - a[i]);
                mnMult = min(mnMult, mult[i]);
                mnDiff = min(mnDiff, diff[i]);
            }
            vector <ll> a_temp;
            for (int i = 0; i < n; ++i) {
                a_temp.push_back(a[i] * mnMult);
            }
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (a_temp[i] != b[i]) ++cnt;
            }
            if (cnt == 1) {
                cout << "2\n";
                return;
            }
            cnt = 0;
            a_temp.clear();
            for (int i = 0; i < n; ++i) {
                a_temp.push_back(a[i] + mnDiff);
            }
            for (int i = 0; i < n; ++i) {
                if (a_temp[i] != b[i]) ++cnt;
            }
            if (cnt == 1) {
                cout << "2\n";
                return;
            }
            //Try with Moves = 3
            cout << n << endl;
        };
        Solve();
    }
    return 0;
}

