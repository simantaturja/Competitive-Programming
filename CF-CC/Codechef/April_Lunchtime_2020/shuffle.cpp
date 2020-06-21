#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
bool cmp (const pair <int, int> &a, const pair <int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return (a.first > b.first);
}
void print(vector <pair <int, int> > &arr) {
    int n = (int)arr.size();
    for (int i = 0; i < n; ++i) {
        cout << arr[i].first << ' ';
    }
    cout << endl;   
}
vector <pair <int, int> > v;
int bs(int target, int n) {
    int l = 0, r = n - 1;
    int mid = (l + r) >> 1;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (v[mid].first == target) {
            return mid;
        } else if (v[mid].first < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d %d", &n, &k);
        vector <int> arr, brr;
        vector <pair <int, int> > crr;
        multimap <int, int> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            arr.push_back(x);
            brr.push_back(x);
            mp.insert({x, i});
        }
        sort(arr.begin(), arr.end());
        //sort(crr.begin(), crr.end(), cmp);
        bool f = 0;
        for (int i = 0; i < n; ++i) {
            int x = arr[i];
            vector <int> v;
            while(true) {
                if (mp.size() == 0) break;
                auto it = mp.find(x);
                if (it->first == x) {
                    v.push_back(it->second);
                    mp.erase(it);
                } else break;
            }
            if ((int)v.size() == 0) {
                f = 1;
                break;
            }
            int in = -1;
            for (int j = 0; j < (int)v.size(); ++j) {
                if (v[j] % k == i % k) {
                    in = j;
                    break;
                }
            }
            if (in == -1) {
                break;
            }
            for (int j = 0; j < (int)v.size(); ++j) {
                if (j != in) mp.insert({x, v[j]});
            }
            if (f) break;
        }
        if (f) printf("no\n");
        else printf("yes\n");
        
    }
    return 0;
}