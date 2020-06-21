/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1742
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 2010
vector <int> adj[MAXN];
bitset <2010> visited;
int n, m;
int bfs ( int src ) {
  visited.reset();
  queue <int> q;
  q.push(src);
  visited.set(src);
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    int sz = (int)adj[u].size();
    for ( int i = 0; i < sz; ++i ) {
      int v = adj[u][i];
      if ( !visited.test(v) ) {
        visited.set(v);
        q.push(v);
      }
    }
  }
  for ( int i = 1; i <= n; ++i ) {
    if ( !visited.test(i) ) return 0;
  }
  return 1;
}
void reset() {
  for ( int i = 1; i <= n; ++i ) adj[i].clear();
}
int main() {
  #ifdef __APPLE__
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
  #endif
  while ( scanf("%d %d", &n, &m) && n != 0 ) {
    for ( int i = 0; i < m; ++i ) {
      int u, v, g;
      scanf("%d %d %d", &u, &v, &g);
      adj[u].push_back(v);
      if ( g == 2 ) adj[v].push_back(u);
    }
    int ans = 0;
    for ( int i = 1; i <= n; ++i ) {
      ans = bfs(i);
      if ( !ans ) break;
    }
    printf("%d\n", ans);
    reset();
  }
  return 0;
}
