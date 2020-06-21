#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        ll p = 2;
        while (true) {
            ll pp = (ll)pow(2, p);
            pp--;
            if (n % pp == 0) {
                cout << n / pp << '\n';
                break;
            }
            ++p;
        }
    }
    return 0;
}