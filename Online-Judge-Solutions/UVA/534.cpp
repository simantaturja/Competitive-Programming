/*
  @Author : Simanta Deb Turja
  @Date   : 11-06-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=475
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <double, double> pdd;
const int inf = -(int)1e9;
vector <pdd> v;
double dist[300][300];
inline double getDistance ( double x1, double y1, double x2, double y2 ) {
  double t1 = abs(x1 - x2), t2 = abs(y1 - y2);
  return sqrt((t1 * t1) + (t2 * t2));
}
int main() {
  #ifdef __APPLE__
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  int n, kase = 1;
  while ( scanf("%d", &n) && n != 0 ) {
    for ( int i = 0; i < n; ++i ) {
      double x, y;
      scanf("%lf %lf", &x, &y);
      v.push_back(pdd(x, y));
    }
    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < n; ++j ) {
        dist[i][j] = -inf;
      }
    }
    for ( int i = 0; i < n; ++i ) {
      for ( int j = i + 1; j < n; ++j ) {
        dist[i][j] = dist[j][i] = getDistance(v[i].first, v[i].second, v[j].first, v[j].second);
      }
    }
    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < n; ++j ) {
        for ( int k = 0; k < n; ++k ) {
          dist[j][k] = min(dist[j][k], max(dist[j][i], dist[i][k]));
        }
      }
    }
    printf("Scenario #%d\n", kase++);
    printf("Frog Distance = %.3lf\n\n", dist[0][1]);
    v.clear();
  }
  return 0;
}
