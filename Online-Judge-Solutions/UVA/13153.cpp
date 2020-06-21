/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=873&page=show_problem&problem=5075
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1010000
int spf[MAXN+100];
set <int> pf[MAXN];
vector <int> v;
bitset <1000100> marked, done;
void sieve() {
  for ( int i = 1; i <= MAXN; i += 2 ) spf[i] = i;
  for ( int i = 2; i <= MAXN; i += 2 ) spf[i] = 2;
  for ( int i = 3; i * i <= MAXN; i += 2 ) {
    if ( spf[i] == i ) {
      for ( int j = i * i; j <= MAXN; j += 2 * i ) {
        spf[j] = i;
      }
    }
  }
}
void primeFactorization( int x ) {
  int p = x;
  while ( x != 1 ) {
    pf[p].insert(spf[x]);
    x /= spf[x];
  }
}
void preProcess ( ) {
  //for ( int i = 1; i <= 1000000; ++i ) primeFactorization ( i );
}
int arr[MAXN], parent[MAXN], _Rank[MAXN];
void init() {
  for ( int i = 1; i <= 1000000; ++i ) parent[i] = i, _Rank[i] = 1;
}
int Find( int x ) {
  if ( parent[x] == x ) return x;
  return parent[x] = Find(parent[x]);
}
void Union ( int x, int y ) {
  int X = Find(x), Y = Find(y);
  if ( X != Y ) {
    if ( _Rank[X] >= _Rank[Y] ) {
      _Rank[X] += _Rank[Y];
      parent[Y] = X;
    }
    else {
      _Rank[Y] += _Rank[X];
      parent[X] = Y;
    }
  }
}
int main() {
  #ifdef __APPLE__
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  #endif
  sieve();
  preProcess();
  int tc;
  scanf("%d", &tc);
  for ( int kase = 1; kase <= tc; ++kase ) {
    int n;
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i ) {
      scanf("%d", &arr[i]);
    }
    init();
    marked.reset();
    v.clear();
    int one = 0;
    for ( int i = 0; i < n; ++i ) {
      if ( arr[i] == 1 ) {
        one++;
        continue;
      }
      if ( !marked.test(arr[i]) ) {
        marked.set(arr[i]);
        v.push_back(arr[i]);
        if ( !done.test(arr[i]) ) primeFactorization(arr[i]), done.set(arr[i]);
      }
    }
    int sz = (int) v.size();
    for ( int i = 0; i < sz; ++i ) {
      int temp = (int)pf[v[i]].size();
      for ( auto it : pf[v[i]] ) {
        Union(v[i],it);
      }
    }
    int ans = 0;
    for ( int i = 0; i < sz; ++i ) {
      if ( parent[v[i]] == v[i] ) ++ans;
    }
    printf("Case %d: %d\n", kase, ans+one);
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
