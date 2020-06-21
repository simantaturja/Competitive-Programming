/*
  @Author : Simanta Deb Turja
  @Date   : 05-05-2019
  Problem Link : http://lightoj.com/volume_showproblem.php?problem=1257
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
#define MAXN 30010
int dist1[MAXN], dist[MAXN];
vector <pii> adj[MAXN];
int d, farNode;
void bfs(int src) {
  memset(dist,-1,sizeof(dist));
  dist[src] = 0;
  queue <int> q;
  d = 0, farNode = 0;
  q.push(src);
  while ( !q.empty() ) {
    int u = q.front();
    q.pop();
    int sz = (int)adj[u].size();
    if ( d < dist[u] ) {
      d = dist[u];
      farNode = u;
    }
    for ( int i = 0; i < sz; ++i ) {
      int v = adj[u][i].first, w = adj[u][i].second;
      if ( dist[v] == -1 ) {
        dist[v] = dist[u] + w;
        q.push(v);
      }
    }
  }
}
int main() {
  int tc;
  scanf("%d", &tc);
  for ( int kase = 1; kase <= tc; ++kase ) {
    int n;
    scanf("%d", &n);
    for ( int i = 0; i < n - 1; ++i ) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      adj[u].push_back(pii(v, w));
      adj[v].push_back(pii(u, w));
    }
    bfs(0);
    bfs(farNode);
    for ( int i = 0; i < n; ++i ) dist1[i] = dist[i];
    bfs(farNode);
    printf("Case %d:\n", kase);
    for ( int i = 0; i < n; ++i ) {
      printf("%d\n", max(dist1[i], dist[i]));
    }
    for ( int i = 0; i < n; ++i ) adj[i].clear();
  }
  return 0;
}
