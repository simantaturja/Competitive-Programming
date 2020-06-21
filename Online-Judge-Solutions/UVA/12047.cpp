/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3198
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100100
const ll inf = (ll)1e18;
struct node {
  ll w;
  int v;
  node (int a, ll b) {
  	v = a;
  	w = b;
  }
	bool operator <(const node &cmp) const {
	 	return cmp.w < w;
	}
};
pair <ll, ll> dist[MAXN], sDist[MAXN], tDist[MAXN];
vector <node> adj[MAXN], radj[MAXN];
int n;
struct sNode {
  int u, v;
  ll w;
  sNode(int _u, int _v, ll _w) {
    u = _u; v = _v; w = _w;
  }
};
vector <sNode> edges;
void dijkstra( int src, bool flag ) {
  for ( int i = 1; i <= n; i++ ) {
    dist[i] = make_pair(inf, 0);
  }
  priority_queue <node> pq;
  pq.push(node(src, 0));
  dist[src] = make_pair(0,0);
  while( !pq.empty() ) {
    node point = pq.top();
    pq.pop();
    int u = point.v;
    ll w = point.w;
    int sz;
    if ( flag ) sz = (int)adj[u].size();
    else sz = (int)radj[u].size();
    for ( int i = 0; i < sz; ++i ) {
      int vv;
      ll ww;
      if ( flag ) {
        vv = adj[u][i].v;
        ww = adj[u][i].w;
      }else {
        vv = radj[u][i].v;
        ww = radj[u][i].w;
      }
      if ( dist[vv].first > dist[u].first + ww ) {
        dist[vv].first = dist[u].first + ww;
        dist[vv].second = ww;//max(dist[vv].second, ww);
        pq.push(node(vv, dist[vv].first));
      }
    }
  }
}
int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    int m, s, t;
    ll p;
    scanf("%d %d %d %d %lld", &n, &m, &s, &t, &p);
    for ( int i = 0; i < m; ++i ) {
      int u, v;
      ll w;
      scanf("%d %d %lld", &u, &v, &w);
      edges.push_back(sNode(u,v,w));
      adj[u].push_back(node(v, w));
      radj[v].push_back(node(u, w));
    }
    dijkstra(s,1);
    for ( int i = 1; i <= n; ++i ) sDist[i].first = dist[i].first, sDist[i].second = dist[i].second;
    dijkstra(t,0);
    for ( int i = 1; i <= n; ++i ) tDist[i].first = dist[i].first, tDist[i].second = dist[i].second;
    ll ans = -inf;
    for ( int i = 0; i < m; ++i ) {
      sNode point = edges[i];
      int x = point.u, y = point.v;
      if ( sDist[x].first + tDist[y].first + point.w <= p ) {
        ans = max(ans, point.w);
      }
    }
    if ( ans < 0 ) ans = -1;
    printf("%lld\n", ans);
    for ( int i = 1; i <= n; ++i ) adj[i].clear(), radj[i].clear(), edges.clear();
  }
  return 0;
}
