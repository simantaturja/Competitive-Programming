#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        int len = (int)s.length();
        vector <int> alp(26, 0);
        for (int i = 0; i < len; ++i) {
            alp[s[i]-'a']++;
        }
        int mn = (int)1e6;
        char ch;
        for (int i = 0; i < 26; ++i) {
            if (alp[i]) {
                if (mn > len - alp[i]) {
                    mn = len - alp[i];
                    ch = (char)(i + 'a');    
                }
            }
        }
        cout << mn << endl;
        string ans = "";
        for (int i = 0; i < len; ++i) {
            ans += ch;
        }
        cout << ans << endl;
    }
    return 0;
}