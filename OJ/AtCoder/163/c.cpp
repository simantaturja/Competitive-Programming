#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
int main() {
    int n;
    cin >> n;
    vector <int> f(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int x;
        cin >> x;
        ++f[x];
    }
    for (int i = 1; i <= n; ++i) {
        cout << f[i] << '\n';
    }
    return 0;
}