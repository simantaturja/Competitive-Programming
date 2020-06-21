/*  Author: Simanta Deb Turja 
    Website: https://simantaturja.github.io
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    ll sum = 0;
    for ( int i = 1; i <= n; ++i ) {
        if ( i % 3 != 0 && i % 5 != 0 ) {
            sum += (ll)i;
        }
    }
    cout << sum << endl;
    return 0;
}