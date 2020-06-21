    #include <bits/stdc++.h>
    #define X first
    #define Y second
    using namespace std;
     
    typedef long long lint;
    typedef pair<int, int> pii;
     
    const int NMAX = 500003;
     
    int a[NMAX], ans[NMAX];
    vector<int> g[NMAX];
     
    int main()
    {
    	int n, m, i, j, x, y;
    	queue<int> Q;
     
    	scanf("%d%d", &n, &m);
    	while (m--) {
    		scanf("%d%d", &x, &y);
    		g[x].push_back(y);
    		g[y].push_back(x);
    	}
    	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
     
    	for (i = 1; i <= n; ++i)
    		if (a[i] == 1) Q.push(i);
    	for (i = 0; i < n; ++i) {
    		if (Q.empty()) return puts("-1"), 0;
    		x = Q.front(); Q.pop();
    		if (a[x] != 1) return puts("-1"), 0;
    		ans[i] = x;
    		for (int p: g[x])
    			if (--a[p] == 1) Q.push(p);
    	}
     
    	for (i = 0; i < n; ++i) printf("%d ", ans[i]);
    	return 0;
    }