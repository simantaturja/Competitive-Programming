#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define mp make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(s) s.begin(),s.end()
#define vll vector<ll>
#define vi vector<int>
#define vpii vector<pii>
#define vpll vector<pll>
#define vull vector<ull>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define fi first
#define se second
#define sz(x) x.size()
#define cinarr(n,a) for(int i = 0; i < n; i++) cin >> a[i];
#define coutarr(n,a) for(int i = 0; i < n; i++) cout << a[i] << (i+1==n?'\n':' ');
#define fori(i,a,b,x) for(int i = a; i <= b; i+=x)
#define ford(i,a,b,x) for(int i = a; i >= b; i-=x)
#define tc int t; cin >> t; for(int cs = 1; cs <= t; cs++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define reset(x,y) memset(x,y,sizeof x);
#define EPS 1e-10
#define INF 2000000000
#define mod 1000000007
#define debug(val) cerr << "The value of " << #val << " is = " << val << endl;
#define testing cerr << "--------------------------\n";
 
ll a[400005],pre[400005],pre2[400005];
 
ll sum(ll l, ll r) {
	return r*(r+1)/2-l*(l+1)/2;
}
 
int main() {
	IOS
	ll n,x;
	cin >> n >> x;
	ll mx=0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mx=max(mx,a[i]);
		pre[i]=pre[i-1]+a[i];
		pre2[i]=pre2[i-1]+a[i]*(a[i]+1)/2;
	}
	for(int i = n+1; i < 2*n; i++) {
		pre[i]=pre[i-1]+a[i-n];
		pre2[i]=pre2[i-1]+a[i-n]*(a[i-n]+1)/2;
	}
	if(x <= mx) {
		ll res=0;
		while(x--) {
			res+=mx--;
		}
		cout<<res<<endl;
		return 0;
	}
	ll res=0;
	for(int i = 0; i < n; i++) {
		auto it = lower_bound(pre+i,pre+2*n,pre[i]+x);
		ll nw = *it-pre[i]-x;
//		debug(i)
//		debug(nw)
//		debug(*it)
		ll tmp=pre2[it-pre]-pre2[i]-nw*(nw+1)/2+sum(nw,*it-pre[i]-x);
//		debug(tmp);
		res=max(res,tmp);
//		testing
	}
	cout<<res<<endl;
}
