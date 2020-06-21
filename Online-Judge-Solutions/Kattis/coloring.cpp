/*
  @Author : Simanta Deb Turja
  @Date   : 02-05-2019
  Problem Link : https://open.kattis.com/problems/coloring
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool adj[20][20];
bitset <20> b, c;
pair <int, int> deg[20];
int d[20];
bool cmp ( const pair <int, int> &a, const pair <int, int> &b ) {
  return a.second > b.second;
}
int main() {
  int n, col = 0;
  scanf("%d", &n);
  string temp;
  getline(cin, temp);
  for ( int i = 0; i < n; ++i ) {
    string line;
    getline(cin, line);
    istringstream is (line);
    int num;
    int cnt = 0;
    while( is >> num ) {
      adj[i][num] = 1;
      d[i]++;
    }
  }
  for ( int i = 0; i < n; i++ ) {
    deg[i] = make_pair(i,d[i]);
  }
  sort( deg,deg + n, cmp );
  for ( int i = 0; i < n; ++i ) {
    int node = deg[i].first;
    if ( b.test(node) ) continue;
    b.set(node);
    col++;
    for ( int j = 0; j < n; j++ ) {
      if ( node != j && !adj[node][j] && !b.test(j) ) {
        b.set(j);
      }
    }
    if ( b.count() == n ) break;
  }
  printf("%d\n", col);
  return 0;
}
