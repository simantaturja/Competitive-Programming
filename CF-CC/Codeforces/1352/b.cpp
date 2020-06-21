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
bool isEven(int n) {
    return n % 2 == 0;
}
bool check(vector <int> &numbers) {
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] - 1 <= 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    FASTIO;
    //#ifdef Professor
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        if (k > n) {
            cout << "NO\n";
            continue;
        }
        int res = n / k, rem = n % k;
        vector <int> numbers;
        for (int i = 0; i < k; ++i) {
            numbers.push_back(res);
        }
        if (rem == 0) {
            cout << "YES\n";
            for (int i = 0; i < k; ++i) {
                cout << numbers[i] << ' ';
            }
            cout << endl;
            continue;
        }
        if (isEven(res + rem) == isEven(res)) {
            cout << "YES\n";
            numbers[0] += rem;
            for (int i = 0; i < k; ++i) {
                cout << numbers[i] << ' ';
            }
            cout << endl;
            continue;
        }
        if (isEven(res + rem + k - 1) == isEven(res - 1) && (res - 1 != 0)) {
            cout << "YES\n";
            numbers[0] += rem + k - 1;
            for (int i = 0; i < k; ++i) {
                if (i == 0) {
                    cout << numbers[i] << ' ';
                } else {
                    cout << numbers[i] - 1 << ' ';
                }
            }
            cout << endl;
        } else {
            cout << "NO\n";
        }
    }
    //#endif
    return 0;
}

