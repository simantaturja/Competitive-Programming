/*
  @Author : Simanta Deb Turja
  @Date   : 29-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1403
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 210
struct node {
  int x, y, cost;
  bool part;
  bool operator<(const node &other) const {
    return cost < other.cost;
  }
};
int n, m, ans, cnt;
node arr[MAXN];
int parent[MAXN], _Rank[MAXN];
bool visited[MAXN];
void init( ) {
  for ( int i = 1; i <= n; ++i ) parent[i] = i, _Rank[i] = 1;
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
int Kruskal( int forbidden ) {
  ans = cnt = 0;
  init();
  for ( int i = 0; i < m; ++i ) {
    if ( i == forbidden ) continue;
    int x = Find(arr[i].x), y = Find(arr[i].y);
    if ( x != y ) {
      Union(x, y);
      if ( forbidden == -1 ) arr[i].part = 1;
      ans += arr[i].cost;
      ++cnt;
      if ( cnt == n - 1 ) break;
    }
  }
  return ans;
}
int main() {
  #ifdef __APPLE__
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
  #endif
  int tc;
  scanf("%d", &tc);
  for ( int kase = 1; kase <= tc; ++kase ) {
    scanf("%d %d", &n, &m);
    for ( int i = 0; i < m; ++i ) arr[i].cost = (int)1e9;
    for ( int i = 0; i < m; ++i ) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      arr[i].x = u, arr[i].y = v;
      arr[i].cost = min(arr[i].cost,c);
      arr[i].part = 0;
    }
    sort ( arr, arr + m );
    Kruskal(-1);
    printf("Case #%d : ", kase);
    if ( cnt < n - 1 ) {
      puts("No way");
    }
    else if ( m == n - 1 ) {
      puts("No second way");
    }
    else {
      int res = (int)1e9;
      bool flag = 0;
      for ( int i = 0; i < m; ++i ) {
        if ( arr[i].part == 1 ) {
          int temp = Kruskal(i);
          if ( cnt == n - 1 ) res = min(res, temp);
        }
      }
      if ( res == (int)1e9 ) {
        puts("No second way");
      }
      else printf("%d\n", res);
    }
  }
  return 0;
}
