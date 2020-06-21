//Author : Simanta Deb Turja

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int toInt(char c) {
    return (int)(c - '0');
}
bool cmp(const tuple <int, int, int> &a, const tuple <int, int, int> &b) {
    if ( get<0>(a) == get<0>(b)) {
        return get<1>(a)  < get<0>(b);
    }
    return get<0>(a) < get<0>(b);
}
int main() {
    int tc;
    cin >> tc;
    int kase = 1;
    while(tc--) {
        int n;
        cin >> n;
        vector <tuple <int, int, int> > v;
        for ( int i = 0; i < n; ++i ) {
            int x, y;
            cin >> x >> y;
            v.push_back(make_tuple(x, y, i));
        }
        sort(v.begin(), v.end(), cmp);
        int endJamie = 0, endCameron = 0;
        string result = "";
        for ( int i = 0; i < n; ++i ) {
            result += "J";
        }
        for ( int i = 0; i < n; ++i ) {
            if ( get<0>(v[i]) >= endCameron ) {
                endCameron = get<1>(v[i]);
                int indx = get<2>(v[i]);
                result[indx] = 'C';
            } else if ( get<0>(v[i]) >= endJamie ) {
                endJamie = get<1>(v[i]);
            } else {
                result = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << kase++ << ": " << result << endl;
    }
    return 0;
}