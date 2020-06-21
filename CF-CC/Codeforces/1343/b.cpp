#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        if ( (n / 2) % 2 != 0 ) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int even, odd;
            even = 0, odd = 0;
            for ( int i = 2; i <= n; i += 2 ) {
                cout << i << ' ';
                even += i;
            }
            for ( int i = 1; i < n - 1; i += 2 ) {
                cout << i << ' ';
                odd += i;
            }
            
            cout << even - odd << '\n';
             
        }
    }
    return 0;
}