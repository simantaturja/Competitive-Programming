/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1310
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <double, double> pdd;
#define MAXN 700
struct node {
  int u, v;
  double cost;
  node ( int x, int y, double _cost ) {
    u = x, v = y, cost = _cost;
  }
  bool operator<(const node &other) const {
    return cost < other.cost;
  }
};
int s, p, parent[MAXN], _Rank[MAXN];
vector <node> arr;
vector <pdd> points;
double getDistance( double x1, double y1, double x2, double y2 ) {
  double temp1 = fabs(x1-x2);
  double temp2 = fabs(y1-y2);
  return (sqrt(temp1*temp1+temp2*temp2));
}
void init() {
  for ( int i = 0; i < p; ++i ) parent[i] = i, _Rank[i] = 1;
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
void reset( ) {
  points.clear(), arr.clear();
}
int main() {
  #ifdef __APPLE__
    //freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
  #endif
  int tc;
  scanf("%d", &tc);
  while ( tc-- ) {
    scanf("%d %d", &s, &p);
    for ( int i = 0; i < p; ++i ) {
      double x, y;
      scanf("%lf %lf", &x, &y);
      points.push_back(pdd(x, y));
    }
    for ( int i = 0; i < p; ++i ) {
      for ( int j = i + 1; j < p; ++j ) {
        double dist = getDistance(points[i].first, points[i].second, points[j].first, points[j].second);
        arr.push_back(node(i, j, dist));
      }
    }
    sort ( arr.begin(), arr.end() );
    int sz = ( int )arr.size();
    int ans = 0;
    init();
    for ( int i = 0; i < sz; ++i ) {
      int u = Find(arr[i].u), v = Find(arr[i].v);
      if ( u != v ) {
        Union(u, v);
        ans++;
        if ( ans == p - s ) {
          printf("%.2lf\n", arr[i].cost); break;
        }
      }
    }
    reset();
  }
  return 0;
}
