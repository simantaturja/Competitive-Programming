/*
  @Author : Simanta Deb Turja
  @Date   : 28-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2169
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, double> pid;
#define MAXN 1010
#define eps 1e-9
int n, r;
struct node {
  int x, y;
  double cost;
  node ( int _x, int _y, double _c ) {
    x = _x, y = _y, cost = _c;
  }
};
bool cmp ( node a, node b ) {
  return a.cost < b.cost;
}
double getDistance ( int x1, int y1, int x2, int y2 ) {
  double X1 = (double)x1, X2 = (double)x2, Y1 = (double)y1, Y2 = (double)y2;
  double ans1 = abs(X1-X2), ans2 = abs(Y1-Y2);
  double ans = sqrt((ans1*ans1)+(ans2*ans2));
  return ans;
}

int parent[MAXN], _Rank[MAXN];
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
vector <pii> arr;
double dist[MAXN][MAXN];
vector <node> edges;
void reset() {
  memset(dist, 0, sizeof(dist));
  arr.clear(), edges.clear();
}
int main() {
  #ifdef __APPLE__
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
  int tc;
  scanf("%d", &tc);
  for ( int kase = 1; kase <= tc; ++kase ) {
    scanf("%d %d", &n, &r);
    for ( int i = 0; i < n; ++i ) {
      int x, y;
      scanf("%d %d", &x, &y);
      arr.push_back(pii(x, y));
    }
    for ( int i = 0; i < n; ++i ) {
      for ( int j = i+1; j < n; ++j ) {
        dist[i][j] = getDistance(arr[i].first, arr[i].second, arr[j].first, arr[j].second);
        dist[j][i] = dist[i][j];
        edges.push_back(node(i, j, dist[i][j]));
      }
    }
    for ( int i = 0; i < n; ++i ) parent[i] = i, _Rank[i] = 1;
    int sz = (int)edges.size();
    sort(edges.begin(), edges.end(), cmp);
    double sum = 0.0, rail = 0.0;
    int state = 1;
    for ( int i = 0; i < sz; ++i ) {
      int x = edges[i].x, y = edges[i].y;
      double cost = edges[i].cost;
      int X = Find(x), Y = Find(y);
      if ( X != Y && cost <= r ) {
        Union(X, Y);
        sum += cost;
      }
      else if ( X != Y ) {
        Union(X, Y);
        rail += cost;
        state++;
      }
    }
    printf("Case #%d: %d %lld %lld\n", kase, state, (ll)round(sum), (ll)round(rail));
    reset();
  }
  return 0;
}
