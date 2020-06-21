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
    while(scanf("%s", str) && str[0] != '.' ) {
        prefixTable(str);
        int len = strlen(str);
        if ( len % (len - pi[len - 1]) == 0 && pi[len - 1] > 0 ) {
            printf("%d\n", len / (len - pi[len - 1]));
        } else {
            printf("1\n");
        }
    }
    return 0;
}
