#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for ( int i = 0; i < m; ++i ) {
        int x;
        cin >> x;
        sum += x;
    }
    if (n - sum >= 0) {
        cout << n - sum << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}