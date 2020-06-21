#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
#define fr first
#define sc second
#define pb push_back
#define mpr make_pair
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define sz(x) int(x.size())
int t, n, a[101], k;
int main() {
	ios_base :: sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n >> k;
		set <int> st;
		for(int i = 1;i <= n; ++ i){
			cin >> a[i];
			st.ins(a[i]);
		}
		if(sz(st) > k){
			cout << "-1\n";
			continue;
		}
		vector <int> g;
		for(auto to : st)g.pb(to);
		for(int i = 1;i <= n; ++ i){
			if(sz(g) >= k){
				while(g[sz(g) - k] != a[i])g.pb(g[sz(g) - k]);
			}
			g.pb(a[i]);
		}
		cout << sz(g) << "\n";
		for(auto to : g)cout << to << " ";
		cout << "\n";
	}
	return 0;
}