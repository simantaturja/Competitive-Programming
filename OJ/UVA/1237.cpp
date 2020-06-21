/*
  @Author : Simanta Deb Turja
  @Date   : 11-06-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3678
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node {
  string name;
  int l, h;
  node ( string _name, int _l, int _h ) {
    name = _name, l = _l, h = _h;
  }
};
vector <node> v;
int main() {
  #ifdef __APPLE__
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  #endif
  int tc, kase = 1;
  scanf("%d", &tc);
  while ( tc-- ) {
    if ( kase != 1 ) puts("");
    ++kase;
    int d;
    scanf("%d", &d);
    string s;
    int l, h;
    for ( int i = 0; i < d; ++i ) {
      cin >> s >> l >> h;
      v.push_back(node(s, l, h));
    }
    int q;
    scanf("%d", &q);
    while ( q-- ) {
      int p;
      scanf("%d", &p);
      int cnt = 0;
      string ans = "";
      for ( int i = 0; i < d; ++i ) {
        if ( v[i].l <= p && v[i].h >= p ) cnt++, ans += v[i].name;
        if ( cnt == 2 ) break;
      }
      if ( cnt == 1 ) cout << ans << "\n";
      else cout << "UNDETERMINED\n";
    }
    v.clear();
  }
  return 0;
}
