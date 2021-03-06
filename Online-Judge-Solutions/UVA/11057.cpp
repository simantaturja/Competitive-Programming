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
    int n;
    while (scanf("%d", &n) == 1) {
        vector <int> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }
        int total_money = 0;
        cin >> total_money;
        sort(prices.begin(), prices.end());
        function <bool(int, int)> found = [&] (int target, int in) {
            int lo = 0, hi = n - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (prices[mid] == target) {
                    if (in != mid) return 1;
                    if (mid != 0 && prices[mid - 1] == target) return 1;
                    if (mid != n - 1 && prices[mid + 1] == target) return 1;
                    return 0; 
                } else if (prices[mid] > target) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            return 0;
        };
        int diff = INF, book1, book2;
        for (int i = 0; i < n; ++i) {
            int find_book = total_money - prices[i];
            if (found(find_book, i)) {
                int temp_diff = abs(find_book - prices[i]);
                if (temp_diff < diff) {
                    diff = temp_diff;
                    book1 = min(find_book, prices[i]);
                    book2 = max(find_book, prices[i]);
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", book1, book2);
    }
    return 0;
}

