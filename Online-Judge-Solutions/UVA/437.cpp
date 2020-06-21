#include <bits/stdc++.h>
using namespace std;
const int N = 210;
struct block {
    int x, y, z;
}blocks[N];
int dp[N], blockno = 0;
void process( int x, int y, int z ) {
    blocks[blockno].x = x;
    blocks[blockno].y = y;
    blocks[blockno].z = z;
    ++blockno;
}
bool cmp(const block &a, const block &b) {
    if ( a.x == b.x ) return a.y > b.y;
    return a.x > b.x;
}
int main() {
    int n, kase = 1;
    while( scanf("%d", &n) && n != 0 ) {
        int x, y, z;
        blockno = 0;
        for ( int i = 0; i < n; ++i ) {
            scanf("%d %d %d", &x, &y, &z);
            process(x, y, z);
            process(x, z, y);
            process(y, x, z);
            process(y, z, x);
            process(z, y, x);
            process(z, x, y);
        }
        sort(blocks, blocks + blockno, cmp);
        int tallest = 0;
        memset(dp, 0, sizeof(dp));
        for ( int i = 0; i < 6 * n; ++i ) {
            dp[i] = blocks[i].z;
            for( int j = 0; j < i; ++j ) {
                if ( blocks[i].x < blocks[j].x && blocks[i].y < blocks[j].y && dp[i] < dp[j] + blocks[i].z ) {
                    dp[i] = dp[j] + blocks[i].z;
                }
            }
            tallest = max(tallest, dp[i]);
        }
        printf("Case %d: maximum height = %d\n", kase++, tallest);
    }
    return 0;
}
