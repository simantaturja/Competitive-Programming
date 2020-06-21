/*  Author: Simanta Deb Turja 
    Website: https://simantaturja.github.io
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 10;
ll arr[N + 7], dp[N + 7][2];
int n;
ll solve ( int pos, int flag ) {
    if ( pos == n ) return 0;
    if ( dp[pos][flag] != -1 ) return dp[pos][flag];
    ll ret = 0;
    if ( flag )
}
int main() {
    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    return 0;
}