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
struct node {
	int len, indx;
	node(int _l , int _i) {
		len = _l;
        indx = _i;
	}
  	bool operator <(const node &cmp) const {
  	 	if (cmp.len == len) {
            return cmp.indx < indx;
        }
        return cmp.len > len;
  	}
};



int main() {
    FASTIO;
    //#ifdef Professor
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        priority_queue <node> pq;
        int in = n / 2;
        if (n % 2 == 0) --in;
        vector <int> arr(n, 0);
        int num = 1;
        pq.push(node(n, in));
        while (!pq.empty()) {
            node u = pq.top();
            pq.pop();
            arr[u.indx] = num++;
            int len = u.len / 2;
            node left = u, right = u;
            if (u.len % 2 == 0) {
                left.len = len - 1;
                right.len = len;
            } else {
                left.len = right.len = len;
            }
            left.indx = u.indx - left.len / 2 - 1;
            right.indx = u.indx + right.len / 2;
            left.indx = u.indx - (left.len / 2) - 1;
            
            if (right.len % 2 != 0) ++right.indx; 

            if (left.len > 0 ) pq.push(left);
            if (right.len > 0) pq.push(right);
        }
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    //#endif
    return 0;
}

