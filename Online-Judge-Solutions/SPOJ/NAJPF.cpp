#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 2;
int pi[N + 7];

void prefixTable(const string &s) {
    int len = (int)s.length();
    int i = 1, j = 0;
    pi[0] = 0;
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
vector <int> indx;
void kmp(const string &text, const string &pattern) {
    int textLength = (int)text.length(), patternLength = (int)pattern.length();
    int i = 0, j = 0;
    indx.clear();
    while ( i < textLength ) {
        if ( text[i] == pattern[j] ) {
            ++i, ++j;
            if ( j == patternLength ) {
                indx.push_back(i - j + 1);
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
}

int main() {
    int tc;
    scanf("%d", &tc);
    while ( tc-- ) {
        string a, b;
        cin >> a >> b;
        prefixTable(b);
        kmp(a, b);
        int sz = (int)indx.size();
        if ( sz == 0 ) {
            printf("Not Found\n");
        } else {
            printf("%d\n", sz);
            for ( int i = 0; i < sz; ++i ) {
                printf("%d", indx[i]);
                if ( i != sz - 1 ) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        if ( tc != 0 ) {
            printf("\n");
        }
    }
    return 0;
}
