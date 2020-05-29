#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a - d) >= (c - b)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}