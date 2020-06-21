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
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    while (scanf("%d %d", &n, &k) == 2) {
        vector <int> dist_camps(n + 2), cumu_dist_camps(n + 2, 0);
        for (int i = 1; i <= n + 1; ++i) {
            cin >> dist_camps[i];
        }
        for (int i = 1; i <= n + 1; ++i) {
            cumu_dist_camps[i] = cumu_dist_camps[i - 1] + dist_camps[i];
        }
        int camps = 0;
        function <bool(int)> valid = [&] (int guess) {
            int dist_guess = guess;
            int dist_sum = 0;
            camps = 0;
            for (int i = 1; i <= n + 1; ++i) {
                if (dist_camps[i] > dist_guess) {
                    return 0;
                }
                if (dist_sum + dist_camps[i] <= dist_guess) {
                    dist_sum += dist_camps[i];
                } else {
                    ++camps;
                    dist_sum = dist_camps[i];
                }
            }
            return  (camps <= k) ? 1 : 0;
        };
        int lo = 0, hi = cumu_dist_camps[n + 1];
        int answer = INF;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            bool check_valid = valid(mid);
            if (check_valid) {
                answer = min(answer, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        printf("%d\n", answer);
    }
    
    return 0;
}

