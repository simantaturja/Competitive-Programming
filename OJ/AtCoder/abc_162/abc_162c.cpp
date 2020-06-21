/*  Author: Simanta Deb Turja 
    Website: https://simantaturja.github.io
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int k;
    cin >> k;
    int g = 0;
    for ( int i = 1; i <= k; ++i ) {
        for ( int j = 1; j <= k; ++j ) {
            for ( int l = 1; l <= k; ++l ) {
                g += __gcd(i, __gcd(j, l));
            }
        }
    }
    cout << g << endl;
    return 0;
}