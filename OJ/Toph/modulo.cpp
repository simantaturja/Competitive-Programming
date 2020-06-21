#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue <pair <ll, int> > q;
vector <pair <ll, int> > res;
bool cmp(pair <ll, int> a, pair <ll, int> b) {
    return a.second < b.second;
}
int main() {
    int tc;
    scanf("%d", &tc);
    for ( int kase = 1; kase <= tc; ++kase ) {
        int n;
        scanf("%d", &n);
        for ( int i = 0; i < n; ++i ) {
            ll x;
            scanf("%lld", &x);
            q.push({x, i});
        }
        int query;
        scanf("%d", &query);
        while(query--) {
            ll m;
            scanf("%lld", &m);
            int sz = (int)q.size();
            int in = 0;
            while ( in < sz ) {
                pair <ll, int> u = q.top();  q.pop();
                if ( u.first < m ) {
                    q.push(u);
                    break;
                }
                u.first = u.first % m;
                if ( u.first > 0 ) q.push(u);
                else res.push_back(u);
                ++in;
            }
        }
        while(!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        printf("Case %d:\n", kase);
        sort(res.begin(), res.end(), cmp);
        int sz = (int)res.size();
        for ( int i = 0; i < sz; ++i ) {
            printf("%d", res[i].first);
            if ( i != sz - 1 ) printf(" ");
        }
        printf("\n");
        res.clear();
    }
    return 0;
}
