#include <stdio.h>
#include <string.h>
using namespace std;
const int N = (int)1e6 + 2;
int pi[N + 7];
void prefixTable(char *s) {
    int len = strlen(s);
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

int main() {
    char str[N + 7];
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%s", str);
        prefixTable(str);
        int len = strlen(str);
        if ( len % (len - pi[len - 1]) == 0 ) {
            printf("%d\n", (len - pi[len - 1]));
        } else {
            printf("%d\n", len);
        }
        if ( tc != 0 ) printf("\n");
    }
    return 0;
}
