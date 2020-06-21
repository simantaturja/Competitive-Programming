/*
  @Author : Simanta Deb Turja
  @Date   : 02-05-2019
  Problem Link : https://open.kattis.com/problems/quickbrownfox
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset <26> bs;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int tc;
  cin >> tc;
  cin.ignore();
  while ( tc-- ) {
    string s;
    getline(cin, s);
    bs.reset();
    int sz = ( int ) s.size();
    for ( int i = 0; i < sz; ++i ) {
      int x = tolower(s[i]) - 'a';
      if ( x >= 0 && x <= 25 ) {
        bs.set(x);
      }
    }
    bool flag = 0;
    for ( int i = 0; i < 26; ++i ) {
      if ( !bs.test(i) ) {
        flag = 1; break;
      }
    }
    if ( !flag ) cout << "pangram\n";
    else {
      cout << "missing ";
      for ( int i = 0; i < 26; ++i ) {
        if ( !bs.test(i) ) cout << (char)(i+'a');
      }
      cout << "\n";
    }
  }
  return 0;
}
