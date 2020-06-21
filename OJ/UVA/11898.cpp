/*
  @Author : Simanta Deb Turja
  @Date   : 30-05-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2998
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200010
int arr[MAXN], n, q;
int freq[10010];
int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &arr[i]);
    scanf("%d", &q);
    while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int limit = r - l + 1;
      bool flag = 0;
      if ( limit >= (int)1e4 ) puts("0");
      else {
        memset(freq,0,sizeof(freq));
        for ( int i = l; i <= r; ++i ) {
          freq[arr[i]]++;
          if ( freq[arr[i]] >= 2 ) {
            puts("0");
            flag = 1;
            break;
          }
        }
        if ( flag ) continue;
        int ans = 1000000, prev = -1;
        for ( int i = 1; i <= 10000; ++i ) {
          if ( freq[i] > 0 ) {
            if ( prev == -1 ) ans = 1000000;
            else ans = min(ans, abs(prev-i));
            prev = i;
          }
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
