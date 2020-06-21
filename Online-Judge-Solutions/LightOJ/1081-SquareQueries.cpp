/*
  @Author : Simanta Deb Turja
  @Date   : 05-05-2019
  Problem Link: http://lightoj.com/volume_showproblem.php?problem=1081
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 510
int n, q, arr[MAXN][MAXN], tree[510][MAXN << 2];
inline void build ( int row, int node, int L, int R ) {
  if ( L == R ) {
    tree[row][node] = arr[row][L];
    return;
  }
  int mid = ( L + R ) >> 1;
  int left = node << 1, right = left|1;
  build ( row, left, L, mid );
  build ( row, right, mid + 1, R );
  tree[row][node] = max(tree[row][left], tree[row][right]);
}

inline int query ( int row, int node, int L, int R, int l, int r ) {
  if ( r < L || l > R ) return 0;
  if ( l <= L && r >= R ) {
    return tree[row][node];
  }
  int mid = ( R + L ) >> 1;
  int left = node << 1, right = left|1;
  int q1 = query(row,left, L, mid, l, r);
  int q2 = query(row,right, mid+1, R, l, r);
  return max(q1 , q2);
}
int main() {
  int tc;
  scanf("%d", &tc);
  for ( int kase = 1; kase <= tc; ++kase ) {
    int n, q;
    scanf("%d %d", &n, &q);
    for ( int i = 1; i <= n; ++i ) {
      for ( int j = 1; j <= n; ++j ) {
        scanf("%d", &arr[i][j]);
      }
    }
    for ( int i = 1; i <= n; ++i ) {
      build(i,1,1,n);
    }
    printf("Case %d:\n", kase);
    while(q--) {
      int l, r, s;
      scanf("%d %d %d", &l, &r, &s);
      int L = l + s - 1, R = r + s - 1;
      int mx = -1;
      for ( int i = l; i <= L; ++i ) {
        mx = max(mx,query(i,1,1,n,r,R));
      }
      printf("%d\n",mx);
    }
  }
  return 0;
}
