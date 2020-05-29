/*
  @Author : Simanta Deb Turja
  @Date   : 03-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2849
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1500000
const ll inf = (ll)1e15;
struct node {
  int u, v, w;
};
vector <int> adj[MAXN];
node edges[MAXN];
bitset <MAXN> visited;
int n, m, cnt;
inline int bfs ( int src ) {  // Runtime: 0.220s
  cnt = 0;
  queue <int> q;
  q.push(src);
  visited.set(src);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    ++cnt;
    int sz = (int)adj[u].size();
    for ( int i = 0; i < sz; ++i ) {
      int v = adj[u][i];
      if ( !visited.test(v) ) {
        q.push(v);
        visited.set(v);
      }
    }
  }
  return cnt;
}
/*int dfs ( int u ) { // Runtime :  0.250s
  visited.set(u);
  int ret = 0;
  for ( int i = 0; i < adj[u].size(); ++i ) {
    if ( !visited.test(adj[u][i]) ) {
      ret += 1 + dfs(adj[u][i]);
    }
  }
  return ret;
}*/
int main() {
  while ( scanf("%d %d", &n, &m) && n != 0 ) {
    ll highest = -inf;
    for ( int i = 0; i < m; ++i ) {
      int u, v, w;
      scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
      highest = max(highest, (ll)edges[i].w);
    }
    for ( int i = 0; i < m; ++i ) {
      if ( highest == edges[i].w ) {
        adj[edges[i].u].push_back(edges[i].v);
        adj[edges[i].v].push_back(edges[i].u);
      }
    }
    int mx = 0;
    for ( int i = 1; i <= n; ++i ) {
      if ( !visited.test(i) ) {
        mx = max(mx, bfs(i));
        //mx = max(mx, dfs(i)+1);
      }
    }
    printf("%d\n", mx);
    for ( int i = 1; i <= n; ++i ) adj[i].clear();
    visited.reset();
  }
  return 0;
}
