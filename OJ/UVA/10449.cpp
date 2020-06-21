/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1390
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 300
const int inf = (int)1e8;
struct node {
  int u, v, w;
}edges[MAXN*MAXN];
int busyness[MAXN], dist[MAXN], n, q, r, kase = 1;
bitset <300> neg;
int main() {
  #ifdef __APPLE__
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
  #endif
  while ( scanf("%d", &n) == 1 ) {
    for ( int i = 1; i <= n; ++i ) {
      scanf("%d", &busyness[i]);
      dist[i] = inf;
    }
    scanf("%d", &r);
    for ( int i = 0; i < r; ++i ) {
      scanf("%d %d", &edges[i].u, &edges[i].v);
      int cost = busyness[edges[i].v] - busyness[edges[i].u];
      edges[i].w = cost * cost * cost;
    }
    dist[1] = 0;
    for ( int iter = 1; iter < n; ++iter ) {
      for ( int i = 0; i < r; ++i ) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if ( dist[u] != inf && dist[v] > dist[u] + w ) {
          dist[v] = dist[u] + w;
        }
      }
    }
    for ( int i = 0; i < r; ++i ) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      if ( dist[v] > dist[u] + w ) {
        dist[v] = dist[u] + w;
        neg.set(v);
      }
    }
    printf("Set #%d\n", kase++);
    scanf("%d", &q);
    while ( q-- ) {
      int junction;
      scanf("%d", &junction);
      int ans = dist[junction];
      if ( ans < 3 || ans >= inf || neg.test(junction) ) {
        printf("?\n");
      }
      else {
        printf("%d\n", ans);
      }
    }
    neg.reset();
  }
  return 0;
}
