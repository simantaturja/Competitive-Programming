/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=989
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200
int c, s, q;
int g[MAXN][MAXN];
int main() {
  #ifdef __APPLE__
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
  #endif
  int kase = 1;
  while ( scanf("%d %d %d", &c, &s, &q) && c != 0 ) {
    if ( kase != 1 ) puts("");
    for ( int i = 1; i <= c; ++i ) {
      for ( int j = i + 1; j <= c; ++j ) {
        g[i][i] = g[i][j] = g[j][i] = (int)1e9;
      }
    }
    for ( int i = 0; i < s; ++i ) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u][v] = w;
      g[v][u] = w;
    }
    for ( int i = 1; i <= c; ++i ) {
      for ( int j = 1; j <= c; ++j ) {
        for ( int k = 1; k <= c; ++k ) {
          g[j][k] = min(g[j][k], max(g[j][i], g[i][k]));
        }
      }
    }
    printf("Case #%d\n", kase++);
    while(q--) {
      int c1, c2;
      scanf("%d %d", &c1, &c2);
      if ( g[c1][c2] == (int)1e9 ) puts("no path");
      else printf("%d\n", g[c1][c2]);
    }
  }
  return 0;
}
