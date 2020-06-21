#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 2;
int pi[N + 7];
void prefixTable(const string &s) {
    int len = (int)s.length();
    int j = 0, i = 1;
    pi[0] = 0;
    while ( i < len ) {
        if ( s[i] == s[j] ) {
            pi[i] = j + 1;
            ++i, ++j;
        } else {
            if ( j == 0 ) {
                pi[j] = 0;
                ++i;
                continue;
            }
            j = pi[j - 1];
        }
    }
}

int kmp(const string &text, const string &pattern) {
    int textLength = (int)text.length(), patternLength = (int)pattern.length();
    int i = 0, j = 0, cnt = 0;
    int mx = 0;
    while ( i < textLength && j < patternLength ) {
        if ( text[i] == pattern[j] ) {
            ++i, ++j;
            if ( j == patternLength ) {
                j = pi[j - 1];
            }
        } else {
            if ( j == 0 ) {
                ++i;
            } else {
                j = pi[j - 1];
            }
        }
    }
    return j;
}

int main() {
    int tc;
    cin >> tc;
    for ( int kase = 1; kase <= tc; ++kase ) {
        string s;
        cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        if ( s == rev ) {
            cout << "Case " << kase << ": " << (int)s.length() << endl;
        } else {
            prefixTable(rev);
            int ans = kmp(s, rev);
            int len = (int)s.length();
            cout << "Case " << kase << ": " << (len << 1) - ans << endl;
        }
    }
    return 0;
}
