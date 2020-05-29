/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1742
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 300
vector <int> adj[MAXN];
int color[MAXN];
int n, m;
int bfs ( int src ) {
  int total = 0, guards = 0;
  queue <int> q;
  q.push(src);
  color[src] = 1;
  while ( !q.empty() ) {
    int u = q.front();
    q.pop();
    total++;
    if ( color[u] == 1 ) guards++;
    int sz = (int)adj[u].size();
    for ( int i = 0; i < sz; ++i ) {
      int v = adj[u][i];
      if ( color[v] == -1 ) {
        color[v] = (color[u]==1)?0:1;
        q.push(v);
      }
      else if ( color[v] != -1 && color[u] == color[v] ) return -1;
    }
  }
  if ( total == 1 ) return 1;
  return min(guards, total-guards);
}
void reset() {
  for ( int i = 0; i < n; ++i ) adj[i].clear();
}
int main() {
  #ifdef __APPLE__
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
  #endif
  int tc;
  scanf("%d", &tc);
  while ( tc-- ) {
    scanf("%d %d", &n, &m);
    for ( int i = 0; i < m; ++i ) {
      int u, v;
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    int ans = 0;
    memset(color,-1,sizeof(color));
    for ( int i = 0; i < n; ++i ) {
      if ( color[i] == -1 ) {
        int temp = bfs(i);
        if ( temp == -1 ) {
          ans = temp;
          break;
        }
        ans += temp;
      }
    }
    printf("%d\n", ans);
    reset();
  }
  return 0;
}
