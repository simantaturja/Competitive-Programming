/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1742
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
#define MAXN 200
const int inf = (int)1e9;
struct node {
  int to, w, lift;
  node ( int _to, int _w, int _lift ) {
    to = _to, w = _w, lift = _lift;
  }
  bool operator<(const node &other) const {
    return w > other.w;
  }
};
vector <pii> edges;
vector <node> adj[MAXN];
bool visited[MAXN][MAXN];
int n, k, t[10], d[MAXN], p[MAXN];
vector <pii> dist[MAXN][MAXN];
vector <int> lift[10];
int dijkstra(int liftNo) {
  priority_queue <node> pq;
  pq.push(node(0,0,liftNo));
  p[0] = liftNo;
  d[0] = 0;
  while ( !pq.empty() ) {
    node point = pq.top();
    pq.pop();
    int from = point.to;
    if ( from == k ) break;
    int sz = (int)adj[from].size();
    for ( int i = 0; i < sz; ++i ) {
      int to = adj[from][i].to, cost = adj[from][i].w, currLift = adj[from][i].lift;
      int extra = 0;
      if ( p[from] != currLift ) extra = 60;
      if ( d[to] > d[from] + extra + cost ) {
        d[to] = d[from] + extra + cost;
        pq.push(node(to, d[to], currLift));
        p[to] = currLift;
      }
    }
  }
  return d[k];
}
vector <int> zero;
void reset() {
  for ( int i = 0; i <= 100; ++i ) {
    adj[i].clear();
    for ( int j = 0; j <= 100; ++j ) {
      dist[i][j].clear();
    }
  }
  for ( int i = 0; i < 5; ++i ) lift[i].clear();
  edges.clear();
  memset(visited,0,sizeof(visited));
  memset(p,0,sizeof(p));
  zero.clear();
}
int main() {
  #ifdef __APPLE__
    freopen("in.txt", "r", stdin);
    freopen("out.txt","w",stdout);
  #endif
  while ( scanf("%d %d", &n, &k) == 2 ) {
    for ( int i = 0; i < n; ++i ) scanf("%d", &t[i]);
    cin.ignore();
    string line;
    for ( int i = 0; i < n; ++i ) {
      getline(cin, line);
      stringstream ss(line);
      int num;
      while(ss >> num) {
        lift[i].push_back(num);
        if ( num == 0 ) {
          zero.push_back(i);
        }
      }
    }
    for ( int i = 0; i < n; ++i ) {
      int sz = (int)lift[i].size();
      for ( int j = 0; j < sz; ++j ) {
        for ( int l = 0; l < sz; ++l ) {
          int from = lift[i][j], to = lift[i][l];
          int cost = abs(from - to) * t[i];
          dist[from][to].push_back(pii(cost, i));
          if ( !visited[from][to] ) {
            edges.push_back(pii(from, to));
            visited[from][to] = 1;
          }
        }
      }
    }
    for ( int i = 0; i <= 100; ++i ) d[i] = inf;
    int sz1 = (int) edges.size();
    for ( int i = 0; i < sz1; ++i ) {
      int u = edges[i].first, v = edges[i].second;
      int sz = (int)dist[u][v].size();
      for ( int j = 0; j < sz; ++j ) {
        adj[u].push_back(node(v, dist[u][v][j].first, dist[u][v][j].second));
      }
    }
    int ans = inf;
    int sz2 = (int)zero.size();
    for ( int i = 0; i < sz2; ++i ) {
      ans = min(ans, dijkstra(zero[i]));
    }
    if ( ans == inf ) puts("IMPOSSIBLE");
    else printf("%d\n", ans);
    reset();
  }
  return 0;
}
