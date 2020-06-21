/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2678
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 2005100
struct node {
  int u, v, cost;
  bool operator<(const node &other) const {
    return cost < other.cost;
  }
};
node arr[MAXN];
int n, m, parent[MAXN], _Rank[MAXN];
void init() {
  for ( int i = 0; i < n; ++i ) parent[i] = i, _Rank[i] = 1;
}
int Find ( int x ) {
  if ( x == parent[x] ) return x;
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
int main() {
  #ifdef __APPLE__
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
  #endif
  while ( scanf("%d %d", &n, &m) && n != 0 ) {
    ll total = 0;
    for ( int i = 0; i < m; ++i ) {
      scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].cost);
      total += (ll)arr[i].cost;
    }
    sort( arr, arr + m );
    ll ans = 0;
    init();
    for ( int i = 0; i < m; ++i ) {
      int x = Find(arr[i].u), y = Find(arr[i].v);
      if ( x != y ) {
        Union(x, y);
        ans += (ll)arr[i].cost;
      }
    }
    printf("%lld\n", total-ans);
  }
  return 0;
}
