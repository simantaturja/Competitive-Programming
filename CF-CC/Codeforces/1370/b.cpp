/*
    Author : Simanta Deb Turja
    Created On: 20/06/20
    Codeforces Round 651 (Div. 2)
*/

#include <bits/stdc++.h>
using namespace std;

#define Professor

using ll = long long;
using i64 = unsigned long long;
using ld = long double;

template <typename T> inline T Min (T a, T b, T c) { 
    return min(a, min(b, c)); 
}
template <typename T> inline T Min (T a, T b, T c, T d) { 
    return min(a, min(b, min(c, d))); 
}
template <typename T> inline T Ceil(T a, T b) { 
    return ((a % b == 0) ? (a / b) : (a / b + 1)); 
} 
template <typename T> inline T Floor(T a, T b) { 
    return a / b; 
}
template <typename T> inline T Power (T a, T p) { 
    T res = 1, x = a; 
    while ( p ) { if ( p & 1 ) res = ( res * x );  x = ( x * x ); p >>= 1; }
    return res; 
}
template <typename T> inline T gcd ( T a, T b ) { 
    a = abs(a); b = abs(b); while ( b ) { a = a % b; swap ( a, b ); } 
    return a;
}
template <typename T> inline T lcm(T x,T y) { 
    return (((x)/gcd((x),(y)))*(y)); 
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

const double EPS = 1e-7;
const double PI = acos(-1.0);
const ll LLINF = (ll)1e18+1;
const int INF = (int)1e9+1; 
const int MOD = (int)1e9 + 7;
const int N = (int)5e5 + 10;


//++++++++++++++++++Template Ends Here++++++++++++++++++

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        function <void(void)> Solve = [&]() {
            int n;
            cin >> n;
            vector <int> arr(2*n);
            vector <int> even_a, odd_a;
            int even = 0, odd = 0;
            for (int i = 0; i < 2 * n; ++i) {
                cin >> arr[i];
                if (arr[i] % 2 == 0) {
                    even_a.push_back(i + 1);
                }
                else {
                    odd_a.push_back(i + 1);
                }
            }
            even = (int)even_a.size();
            odd = (int)odd_a.size();
            if (even % 2 != 0) {
                even_a.pop_back();
                odd_a.pop_back();
                --even, --odd;
            } else {
                if (even != 0) {
                    even_a.pop_back();
                    even_a.pop_back();
                    even -= 2;
                } else {
                    odd_a.pop_back();
                    odd_a.pop_back();
                    odd -= 2;
                }
            }
            for (int i = 0; i < even - 1; i += 2) {
                cout << even_a[i] << ' ' << even_a[i + 1] << endl;
            }
            for (int i = 0; i < odd - 1; i += 2) {
                cout << odd_a[i] << ' ' << odd_a[i + 1] << endl;
            }

        };
        Solve();
    }
    return 0;
}