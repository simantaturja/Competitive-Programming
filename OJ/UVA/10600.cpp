/*
  @Author : Simanta Deb Turja
  @Date   : 29-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1541
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200
struct node {
  int u, v, cost;
  bool part;
  bool operator<(const node &other) const {
    return cost < other.cost;
  }
};
node arr[MAXN*MAXN];
int n, m, parent[MAXN], _Rank[MAXN];
void init( ) {
  for ( int i = 1; i <= n; ++i ) parent[i] = i, _Rank[i] = 1;
}
int Find ( int x ) {
  if ( parent[x] == x ) return x;
  return parent[x] = Find(parent[x]);
}
void Union ( int x, int y ) {
  if ( _Rank[x] >= _Rank[y] ) {
    _Rank[x] += _Rank[y];
    parent[y] = x;
  }
  else {
    _Rank[y] += _Rank[x];
    parent[x] = y;
  }
}
int cnt;
int Kruskal ( int forbidden ) {
  init();
  int ans = 0;
  cnt = 0;
  for ( int i = 0; i < m; ++i ) {
    if ( i == forbidden ) continue;
    int x = Find ( arr[i].u ) , y = Find ( arr[i].v );
    if ( x != y ) {
      Union(x, y);
      ans += arr[i].cost;
      ++cnt;
      if ( forbidden == -1 ) arr[i].part = 1;
      if ( cnt == n - 1 ) break;
    }
  }
  return ans;
}
int main( ) {
  #ifdef __APPLE__
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
  int tc;
  scanf("%d", &tc);
  while ( tc-- ) {
    scanf("%d %d", &n, &m);
    for ( int i = 0; i < m; ++i ) {
      scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].cost);
      arr[i].part = 0;
    }
    sort ( arr, arr + m );
    int s1 = Kruskal(-1);
    int s2 = (int)1e9;
    for ( int i = 0; i < m; ++i ) {
      if ( arr[i].part == 1 ) {
        int temp = Kruskal(i);
        if ( cnt == n - 1 ) {
          s2 = min(s2, temp);
        }
      }
    }
    printf("%d %d\n", s1, s2);
  }
}
