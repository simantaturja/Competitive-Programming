#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector <ll> arr(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int i = 0; 
        ll mxNumber = 0;
        while (i < n) {
            int sign = (arr[i] > 0) ? 0 : 1;
            mxNumber = arr[i];
            i++;
            if (i >= n) {
                sum += (ll)mxNumber;
                break;
            }
            int checkSign = (arr[i] > 0) ? 0 : 1;
            while (sign == checkSign) {
                mxNumber = max(mxNumber, arr[i]);
                i++;
                if (i >= n) break;
                checkSign = (arr[i] > 0) ? 0 : 1;
            }
            sum += (ll)mxNumber;
        }
        
        cout << sum << endl;
    }
    return 0;
}