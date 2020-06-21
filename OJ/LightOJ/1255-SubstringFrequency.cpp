#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 2;
int pi[N + 7];

void prefixTable(const string &s) {
    int len = (int)s.length();
    int i = 1, j = 0;
    while ( i < len ) {
        while ( j > 0 && s[i] != s[j] ) {
            j = pi[j - 1];
        }
        if ( s[i] == s[j] ) {
            ++j;
        }
        pi[i] = j;
        ++i;
    }
}
int kmp(const string &text, const string &pattern) {
    int textLength = (int)text.length(), patternLength = (int)pattern.length();
    int i = 0, j = 0, cnt = 0;
    while ( i < textLength ) {
        if ( text[i] == pattern[j] ) {
            ++i, ++j;
            if ( j == patternLength ) {
                j = pi[j - 1];
                ++cnt;
            }
        } else {
            if ( j == 0 ) {
                ++i;
            } else {
                j = pi[j - 1];
            }
        }
    }
    return cnt;
}
int main() {
    int tc;
    scanf("%d", &tc);
    for ( int kase = 1; kase <= tc; ++kase ) {
        string a, b;
        cin >> a >> b;
        prefixTable(b);
        int ans = kmp(a, b);
        printf("Case %d: %d\n", kase, ans);
    }
    return 0;
}
