#include<bits/stdc++.h>
using namespace std;
#define int double
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frn(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define test int t;cin>>t; while(t--)
#define mp make_pair
#define pb push_back
#define pu push
#define mod 1000000007
void fast() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
}
int32_t main() {
	fast();
	test{
		int h,c,t;
		cin>>h>>c>>t;
		if(t<= (h+c)/2) cout<<"2"<<endl;
		else if(t == h) cout<<"1"<<endl;
		else{
			long long s = 1;
			long long e = 10001;
			long long ans = 2;
			int diff=t-(h+c)/2;
			while(s<=e){
				long long m = s+(e-s)/2;
				
				int k = (h)*((double)(m+1)) + c*(double)(m);
				k /= double(m);
				if(k>t){
					if(k-t<diff){
						diff = k-t;
						
						ans = 2*m+1;
						
					}
					s = m+1;
				}
				else if(k==t){
					ans = m;
					break;
				}
				else if(k<t){
					if(t-k<diff){
						diff = t-k;
						ans = 2*m+1;
						if(m%2==0) ans++;
					}
					e = m-1;
				}
			}
			cout<<ans<<endl;
		}
	}
}
