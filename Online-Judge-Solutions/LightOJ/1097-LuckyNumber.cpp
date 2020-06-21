/*
  @Author : Simanta Deb Turja
  @Date   : 05-05-2019
  Problem Link : http://lightoj.com/volume_showproblem.php?problem=1097
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define MAXN 1450000
typedef tree< int, null_type, less<int>, rb_tree_tag,
  tree_order_statistics_node_update> orderedSet;
  orderedSet os;
void pre() {
  os.insert(0);
  for ( int i = 1; i <= MAXN-10; i += 2 ) {
    os.insert(i);
  }
  for ( int i = 2; i <= 10000; ++i ) {
    auto it1 = os.find_by_order(i);
    for ( int j = *it1, k = 0; j <= MAXN-10 && j > k; j += *it1, ++k ) {
      auto it = os.find_by_order( j - k );
      os.erase(it);
    }
  }
}
int main() {
  #ifdef __APPLE__
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  pre();
  int tc;
  scanf("%d", &tc);
  for ( int kase = 1; kase <= tc; ++kase ) {
    int n;
    scanf("%d", &n);
    printf("Case %d: %d\n", kase, *os.find_by_order(n));
  }
  return 0;
}
