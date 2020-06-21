#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n, s;
        scanf("%d %d", &n, &s);
        vector <int> arr(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        vector <int> def, str;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if (x == 0) def.push_back(arr[i]);
            else str.push_back(arr[i]);
        }
        sort(def.begin(), def.end());
        sort(str.begin(), str.end());
        if (def.size() == 0 || str.size() == 0) {
            printf("no\n");
            continue;
        }
        if (s + def[0] + str[0] <= 100) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}