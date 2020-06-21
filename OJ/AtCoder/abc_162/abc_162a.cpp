/*  Author: Simanta Deb Turja 
    Website: https://simantaturja.github.io
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    for ( int i = 0; i < 3; ++i ) {
        if ( s[i] == '7' ) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}