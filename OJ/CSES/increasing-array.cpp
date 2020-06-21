#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector <ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll moves = 0LL;
    for (int i = 1; i < n; ++i) {
        ll temp = 0LL;
        if (arr[i - 1] > arr[i]) temp = abs(arr[i - 1] - arr[i]);
        moves += temp;
        arr[i] += temp;
    }
    cout << moves << endl;
    return 0;
}