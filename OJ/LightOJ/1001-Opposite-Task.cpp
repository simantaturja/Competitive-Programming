#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int tc, kase = 1;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        if (n > 10) {
            printf("%d %d\n", n - 10, 10);
        } else {
            printf("%d %d\n",0, n);
        }
    }
    return 0;
}