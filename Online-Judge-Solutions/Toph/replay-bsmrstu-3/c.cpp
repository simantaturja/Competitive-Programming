#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cal(int n, int d)
{
	if(n == 1) return 1;
	if(n % 2 == 1)
	{
		return cal(n - 1, d) + (n - 1) * d;
	}
	else
	{
		return cal(n - 1, d) - (n - 1) * d;
	}
}
int main() {
    /*int s = 0;
    int n1 = 1, d1 = 1;
    for (int d = 1; d <= 10; ++d) {
        s = 0;
        for (int n = 1; n <= 10; ++n) {
            s += cal(n, d);
            cout << n << ' ' << d << ": " << s << endl;
        }
        cout << "========================\n";
    }*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tc;
    cin >> tc;
    while(tc--) {
        ll n, d;
        cin >> n >> d;
        if (n == 1) {
            cout << "1\n";
            continue;
        } 
        ll sum1 = 0, sum2 = 0;
 
        if (n % 2 ==1 ) {
            ll l = n/2 + 1;
            ll temp = (2 + (l - 1) * d);
            sum1 = (l * temp) / 2;
            l=n/2;
            temp = (2 *(d-1) + (l - 1) * d);
            sum2 = (l * temp) / 2;
        } else {
            ll l = n/2;
            ll temp = (2 + (l - 1) * d);
            sum1 = (l * temp) / 2;
            l=n/2;
            temp = (2 *(d-1) + (l - 1) * d);
            sum2 = (l * temp) / 2;
        }

        cout << sum1 - sum2 << endl;
    }
    return 0;
}