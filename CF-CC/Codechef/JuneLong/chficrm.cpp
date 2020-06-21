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
            int n;
            cin >> n;
            int chefHas = 0, valid = 1, rs5 = 0, rs10 = 0, rs15 = 0;
            function<bool(int)> make = [&](int rs) {
                int rs15_temp = rs15, rs10_temp = rs10, rs5_temp = rs5;
                while (rs > 0 && rs % 15 == 0 && rs15_temp > 0) {
                    rs -= 15;
                    rs15_temp--;
                }
                while (rs > 0 && rs % 10 == 0 && rs10_temp > 0) {
                    rs -= 10;
                    rs10_temp--;
                }
                while (rs > 0 && rs % 5 == 0 && rs5_temp > 0) {
                    rs -= 5;
                    rs5_temp--;
                }
                if (rs == 0) {
                    rs15 = rs15_temp; rs10 = rs10_temp; rs5 = rs5_temp;
                    return 1;
                }
                return 0;
            };
            
            for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                int back = x - 5;
                //cout << rs15 << ' ' << rs10 << ' ' << rs5 << endl; 
                if (chefHas >= back && make(back)) {
                    if (x == 15) rs15++;
                    else if (x == 10) rs10++;
                    else if (x == 5) rs5++;
                    chefHas += 5;
                } else {
                    valid = 0;
                }
            }
            if (!valid) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
            
        };
        Solve();
    }
    return 0;
}

