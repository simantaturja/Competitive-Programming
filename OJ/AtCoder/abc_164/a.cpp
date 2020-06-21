#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int s, w;
    cin >> s >> w;
    if (s <= w) {
        cout << "unsafe\n";
    } else {
        cout << "safe\n";
    }
    return 0;
}