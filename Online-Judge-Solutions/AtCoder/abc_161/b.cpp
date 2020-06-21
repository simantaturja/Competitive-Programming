#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    int threshold = 4 * m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x * threshold > 1) m--;
    }
    if (m <= 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}