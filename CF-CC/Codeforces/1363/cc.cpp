#include <bits/stdc++.h>
 
using namespace std;
 
int n, x;
vector<int> degree;
vector<vector<int> > adj;
 
bool util(set<int> leaf){
    for(int i: leaf){
        if(i==x)
            return true;
        if(adj[i].size()>0){
            degree[adj[i][0]]--;
            if(degree[adj[i][0]]<=1)
                leaf.insert(adj[i][0]);
        }
        leaf.erase(i);
        if(!util(leaf))
            return true;
        leaf.insert(i);
        if(adj[i].size()>0){
            degree[adj[i][0]]++;
            if(degree[adj[i][0]]<=2)
                leaf.erase(adj[i][0]);
        }
    }
    return false;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--){
        cin >> n >> x;
        adj=vector<vector<int> >(n+1);
        degree=vector<int>(n+1, 0);
        set<int> leaf;
        for(int i=1; i<=n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        for(int i=1; i<=n; i++)
            if(degree[i]<=1)
                leaf.insert(i);
        if(util(leaf))
            cout << "Ayush" << endl;
        else
            cout << "Ashish" << endl;
 
    }
 
	return 0;
}
