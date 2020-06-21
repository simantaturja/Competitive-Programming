#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int len = (int)s.length();
    int mx = 0, cnt = 1;
    s += "#";
    for (int i = 0; i < len; ++i) {
        if (s[i] == s[i + 1]) {
            ++cnt;
        } else {
            mx = max(mx, cnt);
            cnt = 1;
        }
    }
    cout << mx << endl;
    return 0;
}