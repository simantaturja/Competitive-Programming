/*
  @Author : Simanta Deb Turja
  @Date   : 11-06-2019
  Problem Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=565
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000], arr[1000], mx = 0;
vector <int> temp, ans;
int n, cap;
int solve( int pos, int sum ) {
  if ( sum > cap ) return -1000000;
  if ( pos == n ) {
    if ( mx < sum ) {
      mx = sum;
      ans = temp;
    }
    return 0;
  }
  if ( dp[pos][sum] != -1 ) return dp[pos][sum];
  int ret = 0;
  temp.push_back(arr[pos]);
  ret = arr[pos] + solve(pos+1, sum+arr[pos]);
  temp.pop_back();
  ret = max(ret, solve(pos+1,sum));
  return dp[pos][sum] = ret;
}
int main() {
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w", stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while ( cin >> cap >> n ) {
    for ( int i = 0; i < n; ++i ) cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    temp.clear(); ans.clear();
    mx = 0;
    int res = solve(0,0);
    int sz = (int) ans.size();
    for ( int i = 0; i < sz; ++i ) {
      cout << ans[i] << ' ';
    }
    cout << "sum:" << res << "\n";
  }
  return 0;
}
