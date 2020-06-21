 #include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	vector<int> v;
	REP(i,0,n-1){
		int x;cin>>x;
		v.push_back(x);
	}
	int m = 0;
	int max_so_far = 0;
	int sum = 0;
	REP(i,0,n-1){
		sum+=v[i];
		m = max(m,v[i]);
		if(sum < 0){
			sum = 0;
		}
		max_so_far = max(max_so_far,sum);
		max_so_far-=m;
	}
	cout<<max_so_far<<"\n";
	return 0;
}

