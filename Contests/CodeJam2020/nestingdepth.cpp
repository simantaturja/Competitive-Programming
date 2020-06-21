//Author : Simanta Deb Turja

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int toInt(char c) {
    return (int)(c - '0');
}
int main() {
    int tc;
    cin >> tc;
    int kase = 1;
    while(tc--) {
        string s;
        cin >> s;
        string result = "";
        int len = (int)s.length();
        for ( int i = 0; i < len; ++i ) {
            int k = toInt(s[i]);
            for ( int j = 0; j < k; ++j ) {
                int rLen = (int)result.length();
                if ( result[rLen - 1] == ')' ) {
                    result.erase(rLen - 1, '(');
                } else {
                    result.insert(result.end(), '(');
                }
            }
            result.insert(result.end(), s[i]);
            for ( int j = 0; j < k; ++j ) {
                result.insert(result.end(), ')');
            }
        }
        cout << "Case #" << kase++ << ": " << result << endl;

    }
    return 0;
}