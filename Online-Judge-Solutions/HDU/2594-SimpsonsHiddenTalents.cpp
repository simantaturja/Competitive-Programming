#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
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
    int i = 0, j = 0;
    while ( i < textLength ) {
        if ( text[i] == pattern[j] ) {
            ++i, ++j;
            if ( i == textLength ) {
                return j;
            }
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
    string s1, s2;
    while (cin >> s1 >> s2) {
        prefixTable(s1);
        int ans = kmp(s2, s1);
        if ( ans == 0 ) {
            printf("0\n");
        } else {
            for ( int i = 0; i < ans; ++i ) {
                printf("%c", s1[i]);
            }
            printf(" %d\n", ans);
        }
    }
    return 0;
}
