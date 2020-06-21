/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2847
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 25100
struct node {
  int u, v, cost;
  bool operator<(const node &other) const {
    return cost < other.cost;
  }
};
node arr[MAXN];
int n, m, parent[1010], _Rank[1010];
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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  while ( scanf("%d %d", &n, &m) && n != 0 ) {
    for ( int i = 0; i < m; ++i ) {
      scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].cost);
    }
    sort( arr, arr + m );
    vector <int> ans;
    init();
    for ( int i = 0; i < m; ++i ) {
      int x = Find(arr[i].u), y = Find(arr[i].v);
      if ( x == y ) {
        ans.push_back(arr[i].cost);
      }
      Union(x, y);
    }
    int sz = (int)ans.size();
    if ( sz == 0 ) puts("forest");
    else {
      sort ( ans.begin(), ans.end() );
      for ( int i = 0; i < sz; ++i ) {
        printf("%d", ans[i]);
        if ( i != sz - 1 ) printf(" ");
      }
      puts("");
    }
  }
  return 0;
}
