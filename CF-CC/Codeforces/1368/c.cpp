/*
    Author : Simanta Deb Turja
    Created On: 16/06/20
    Codeforces Round 650 (Div. 3)
    Task A.
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
const int MOD = (ll)1e9 + 7;
const int N = (int)5e5 + 10;


//++++++++++++++++++Template Ends Here++++++++++++++++++
vector <int> dx({0, -1, -1});
vector <int> dy({1, 0, 1});

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    function <void(void)> Solve = [&]() {
        int n;
        cin >> n;
        vector <ii> ans;
        ans.emplace_back(0, 0); ans.emplace_back(-1, 0); ans.emplace_back(0, -1); ans.emplace_back(1, 0);
        ans.emplace_back(0, 1); ans.emplace_back(-1, 1); ans.emplace_back(1, -1);
        int cnt = 1, cx = -1, cy = 1;
        while (cnt < n) {
            for (int i = 0; i < 3; ++i) {
                int x = cx + dx[i], y = cy + dy[i];
                ans.emplace_back(x, y);
                if (i == 2) {
                    cx = x, cy = y;
                }
            }
            ++cnt;
        }
        int ans_sz = (int)ans.size();
        cout << ans_sz << endl;
        for (auto it : ans) {
            cout << it.first << ' ' << it.second << endl;
        }
    };

    Solve();
    
    return 0;
}