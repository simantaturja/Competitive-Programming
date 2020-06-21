/*
  @Author : Simanta Deb Turja
  @Date   : 29-04-2019
  Problem Link : http://lightoj.com/volume_showproblem.php?problem=1087
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
vector <int> a;
int tc, n, q;
int main() {
  #ifdef __APPLE__
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  typedef tree< int, null_type, less<int>, rb_tree_tag,
  tree_order_statistics_node_update> orderedSet;
  scanf("%d", &tc);
  for ( int kase = 1; kase <= tc; ++kase ) {
    printf("Case %d:\n", kase);
    scanf("%d %d", &n, &q);
    orderedSet os;
    for ( int i = 0; i < n; ++i ) {
      int x;
      scanf("%d", &x);
      os.insert(i);
      a.push_back(x);
    }
    int nxt = n;
    while(q--) {
      char c;
      int num;
      scanf(" %c %d", &c, &num);
      if ( c == 'c' ) {
        if ( num > (int)os.size() ) printf("none\n");
        else {
          auto ans = os.find_by_order(num-1);
          printf("%d\n",a[*ans]);
          os.erase(ans);
        }
      }
      else {
        a.push_back(num);
        os.insert(nxt);
        ++nxt;
      }
    }
    a.clear();
  }
  return 0;
}
