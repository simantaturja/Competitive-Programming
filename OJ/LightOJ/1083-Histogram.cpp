#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 2;
typedef pair <int, int> pii;
int arr[N + 7], Right[N + 7], Left[N + 7];
stack <pii> st;
int main() {
	int tc;
	scanf("%d", &tc);
	for ( int kase = 1; kase <= tc; ++kase ) {
		int n;
		scanf("%d", &n);
		for ( int i = 1; i <= n; ++i ) {
			scanf("%d", &arr[i]);
		}
		arr[n + 1] = 0;
		for ( int i = 1; i <= n + 1; ++i ) {
			if ( st.empty() ) {
				st.push(pii(arr[i], i));
			} else {
				while(st.empty() == 0 && st.top().first > arr[i] ) {
					Right[st.top().second] = i - 1;
					st.pop();
				}
				st.push(pii(arr[i], i));
			}
		}
		while(!st.empty()) {
			Right[st.top().second] = n;
			st.pop();
		}
		arr[0] = 0;
		for ( int i = n; i >= 0; --i ) {
			if ( st.empty() ) {
				st.push(pii(arr[i], i));
			} else {
				while(st.empty() == 0 && st.top().first > arr[i] ) {
					Left[st.top().second] = i + 1;
					st.pop();
				}
				st.push(pii(arr[i], i));
			}
		}
		while(!st.empty()) {
			Left[st.top().second] = 1;
			st.pop();
		}

		int mx = 0;
		for ( int i = 1; i <= n; ++i ) {
			mx = max(mx, (Right[i] - Left[i] + 1) * arr[i]);
		}
		printf("Case %d: %d\n", kase, mx);
	}
	return 0;
}
