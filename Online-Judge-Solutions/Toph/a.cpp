#include <bits/stdc++.h>
using namespace std;


int main() {
    string n;
    cin >> n;
    int len = (int)n.size();
    int indx = len - 1;
    for (int i = len - 1; i >= 0; --i) {
        if (n[i] != '0') {
            indx = i;
            break;
        }
    }
    for (int i = 0; i <= indx; ++i) {
        cout << n[i];
    }
    cout << "\nStay at Home\n";
    return 0;
}