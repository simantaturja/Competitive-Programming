/*  Author: Simanta Deb Turja 
    Website: https://simantaturja.github.io
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int r = 0, g = 0, b = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( s[i] == 'R' ) ++r;
        else if ( s[i] == 'G' ) ++g;
        else ++b;
    }
    ll cnt = (ll)r * (ll)g * (ll)b;

    for ( int i = 0; i < n; ++i ) {
        for ( int j = i + 1; j < n; ++j ) {
            if ( s[i] != s[j] && 2*j - i < n && s[i] != s[2*j - i] && s[j] != s[2*j - i] ) --cnt;
        }
    }

    
    cout << cnt << endl;
    return 0;
}