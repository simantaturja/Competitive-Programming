 #include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<vector<int>> vvi;
typedef vector<vector<int>> vi;
typedef pair<pair<int,int>, int> ppiii;
typedef pair<int, pair<int,int>> pipii;
typedef pair<int,char> pic;
typedef pair<char,int> pci;
typedef pair<string,string> pss;
 
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> in(n);
  for (auto& it : in) cin >> it;
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + in[i];
  }
  ll re = -1;
  for (int k = 1; k <= n; k++) {
      bool fine = true;
      for (int i = k; i <= n; i += k) {
          ll diff = pref[i] - pref[i - k];
          if (diff < 0) {
              fine = false;
              break;
          }
      }
      if (fine) {
          re = k;
          break;
      }
  }
  cout << re;
}
