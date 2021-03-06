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
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w",stdout)

const int N = (int)4e5 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const ll LLINF = (ll)1e18+1;
const int INF = (int)1e9+1;
const ll MOD = (ll)1e9 + 7;

template <typename T> bool cmp (const pair <T, T> &a, const pair <T, T> &b) { return a.first < b.first; }


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        vector <ll> vessels(n + 1), cumu_capacity_vessels(n + 1, 0LL);
        for (int i = 1; i <= n; ++i) {
            cin >> vessels[i];
        }
        
        for (int i = 1; i <= n; ++i) {
            cumu_capacity_vessels[i] = cumu_capacity_vessels[i - 1] + vessels[i];
        }
        function<bool(ll)> valid = [&](ll cap) {
            ll milk_taken = 0LL;
            int parts_cnt = 0;
            for (int i = 1; i <= n; ++i) {
                if (vessels[i] > cap) {
                    return 0;
                }
                if (milk_taken + vessels[i] <= cap) {
                    milk_taken += vessels[i];
                } else {
                    milk_taken = vessels[i];
                    ++parts_cnt;
                }
            }
            return (parts_cnt <= m - 1) ? 1 : 0;
        };
        ll lo = 0LL, hi = cumu_capacity_vessels[n];
        ll answer = LLINF;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2LL;
            bool check_valid = valid(mid);
            if (check_valid) {
                answer = min(answer, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        printf("%lld\n", answer);
    }
    return 0;
}

