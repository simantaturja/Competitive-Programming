#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
int arr[N + 7], st[2][N + 7][30], lg[N + 7];
int n, q;
void build_st() {
    lg[1] = 0;
    for ( int i = 2; i <= n; ++i ) {
        lg[i] = lg[i / 2] + 1;
    }
    for ( int i = 0; i < n; ++i ) {
        st[0][i][0] = arr[i];
        st[1][i][0] = arr[i]; // 0 for min, 1 for max
    }
    int K = lg[n];
    for ( int j = 1; j <= K; ++j ) {
        for ( int i = 0; i + (1 << j) <= n; ++i ) {
            st[0][i][j] = min(st[0][i][j - 1], st[0][i + (1 << (j - 1))][j - 1]);
            st[1][i][j] = max(st[1][i][j - 1], st[1][i + (1 << (j - 1))][j - 1]);
        }
    }
}
int main() {
    cin >> n;
    for ( int i = 0; i < n; ++i ) {
        cin >> arr[i];
    }
    build_st();
    cin >> q;
    
    while(q--) {
        double t = 0.0;
        int L,R;
        cin >> L >> R;
        int j = lg[R - L + 1];
        int minimumLR = min(st[0][L][j], st[0][R - (1 << j) + 1][j]);
        int maximumLR = max(st[1][L][j], st[1][R - (1 << j) + 1][j]);
        int l1 = 0, r1 = L - 1, l2 = R + 1, r2 = n - 1;
        int j1 = lg[r1 - l1 + 1], j2 = lg[r2 - l2 + 1];
        int maximumOuterLR1 = max(st[1][l1][j1], st[1][r1 - (1 << j1) + 1][j1]);
        int maximumOuterLR2 = max(st[1][l2][j2], st[1][r2 - (1 << j2) + 1][j2]);
        int mxOuterLR = max(maximumOuterLR1, maximumOuterLR2);
        if ( r1 < 0 && l2 > n - 1) {
            mxOuterLR = 0;
        }
        else if ( r1 < 0 ) mxOuterLR = maximumOuterLR2;
        else if ( l2 > n - 1 ) mxOuterLR = maximumOuterLR1;
        
        t = minimumLR * 1.0 + max((double)(maximumLR - minimumLR) / 2.0, (double)mxOuterLR);
        printf("%.1lf\n", t);
    }
    
    return 0;
}