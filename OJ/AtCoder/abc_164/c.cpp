#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set <string> st;
    while(n--) {
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << (int)st.size() << endl;
    return 0;
}