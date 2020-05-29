#include <bits/stdc++.h>
using namespace std;
bool infected[510 * 510];
int main() {
    int n;
    cin >> n;
    int id = 1;
    char ch;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> ch;
            if (ch == 'c') {
                infected[id] = 1;
            }
            ++id;
        }
    }
    int x;
    cin >> x;
    bool isInfected = 0;
    for (int i = 0; i < x; ++i) {
        int y;
        cin >> y;
        if (infected[y] && !isInfected) {
            isInfected = 1;
            cout << "YES\n";
            continue;
        }
        if (!infected[y] && isInfected) {
            cout << y << ' ';
        }
    }
    if (!isInfected) {
        cout << "NO";
    }
    cout << "\n";
    return 0;
}