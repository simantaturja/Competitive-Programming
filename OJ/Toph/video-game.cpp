#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 10;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    vector <ll> h(n), a(n);
    vector <ll> forward(n + 1), backward(n + 1), forward_equal(n + 1), backward_equal(n + 1) ;
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> a[i];
        forward[i] = backward[i] = a[i];
    }
    
    for (int i = n - 1; i >= 1; --i) {
        if (h[i] <= h[i - 1]) {
            forward[i - 1] += forward[i];
        }
        if (h[i] == h[i - 1]) {
            forward_equal[i - 1] = forward_equal[i] + a[i];
        }    
    }
    
    for (int i = 1; i < n; ++i) {
        if (h[i] >= h[i - 1]) {
            backward[i] += backward[i - 1];
        }
        if (h[i] == h[i - 1]) {
            backward_equal[i] = backward_equal[i - 1] + a[i - 1];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << max(forward[x - 1] + backward_equal[x - 1], backward[x - 1] + forward_equal[x - 1]) << endl;
    }
    return 0;
}