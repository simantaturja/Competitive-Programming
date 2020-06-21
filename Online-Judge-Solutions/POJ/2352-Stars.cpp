#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 32100;
vector <int> v;
int tree[N << 2], lvl[N];
void build ( int node, int L, int R ) {
    if ( L == R ) {
        tree[node] = 0;
        return;
    }
    int mid = ( L + R ) >> 1;
    int left = node << 1, right = left | 1;
    build ( left, L, mid );
    build ( right, mid + 1, R );
    tree[node] = tree[left] + tree[right];
}
int query ( int node, int L, int R, int l, int r ) {
    if ( r < L || l > R ) return 0;
    if ( L >= l && R <= r ) {
        return tree[node];
    }
    int mid = ( L + R ) >> 1;
    int left = node << 1, right = left | 1;
    int q1 = query(left,L,mid,l,r);
    int q2 = query(right,mid+1,R,l,r);
    return q1+q2;
}
void update ( int node, int L, int R, int pos, int value ) {
    if ( pos < L || pos > R ) return;
    if ( L == R ) {
        tree[node] += value;
        return;
    }
    int mid = ( L + R ) >> 1;
    int left = node << 1, right = left | 1;
    update(left,L,mid,pos,value);
    update(right,mid+1,R,pos,value);
    tree[node] = tree[left] + tree[right];
}

int main() {
    int n;
    scanf("%d", &n);
    int mx = 0;
    for ( int i = 0; i < n; ++i ) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back(x+1);
        mx = max(x + 1, mx);
    }
    build(1, 1, mx);
    for ( int i = 0; i < n; ++i ) {
        int pos = query(1, 1, mx, 1, v[i]);
        lvl[pos]++;
        update(1, 1, mx, v[i], 1);
    }
    for ( int i = 0; i < n; ++i ) {
        printf("%d\n", lvl[i]);
    }
    return 0;
}
