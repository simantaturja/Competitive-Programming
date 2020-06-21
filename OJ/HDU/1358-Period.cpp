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
int main() {
    int n;
    int kase = 0;
    while(scanf("%d", &n) && n != 0) {
        string s;
        cin >> s;
        prefixTable(s);
        printf("Test case #%d\n", ++kase);
        for ( int i = 1; i < n; ++i ) {
            if ( pi[i] != 0 && (i + 1 - pi[i] != 0) && (i + 1) % (i + 1 - pi[i]) == 0 ) {
                printf("%d %d\n", i + 1, (i + 1)/(i + 1 - pi[i]));
            }
        }
        printf("\n");
    }
    return 0;
}
