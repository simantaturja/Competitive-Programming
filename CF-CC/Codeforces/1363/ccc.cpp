#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t, n, x, u, v;
	cin>>t;
	bool win = true;
	for(int i=0; i<t; i++){
		bool removed=false;
		cin>>n>>x;
		vector<vector<int>> e(n+1);
		vector<int> degrees(n+1,0);
		for(int j=1; j<=n-1; j++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			degrees[u]++; degrees[v]++;
		}
		if(degrees[x]%2){
			cout << "Ayush\n";
		}
		else{
			cout << "Ashish\n";
		}
	}
	return 0;
}
