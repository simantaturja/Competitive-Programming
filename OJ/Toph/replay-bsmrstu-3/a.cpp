#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        long double a, b;
        cin >> a >> b;
        long double ans = (a + b) / 2.0;
        printf("%.1Lf\n", ans);
    }
    return 0;
}