#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 10;

struct Trie {
    vector <vector <int> > tree, end;
    vector <int> exists;
    int sz;
    Trie(int n) {
        tree.resize(11); end.resize(11);
        for (int i = 0; i < 11; ++i) tree[i].resize(n * 10 + 10), end[i].resize(n * 10 + 10);
        exists.resize(n * 10 + 10);
        sz = 0;
    }

    bool insert(string &s) {
        int v = 0;
        int len = (int)s.length();
        for (int i = 0; i < len; ++i) {
            if (!exists[tree[s[i]-'0'][v]]) {
                tree[s[i] - '0'][v] = ++sz;
                exists[tree[s[i] - '0'][v]] = sz;
            }
            if (end[s[i]-'0'][v]) return false;
            if (i == len - 1) {
                end[s[i]-'0'][v] = 1;
            }
            v = tree[s[i]-'0'][v];
        }
        return true;
    }
};


int main() {
    int tc, kase = 1;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector <string> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return (int)a.length() < (int)b.length();
        });
        Trie t = Trie(n);
        bool bad = 0;
        for (int i = 0; i < n; ++i) {
            if (!t.insert(v[i])) {
                bad = 1;
                break;
            }
        }
        if (!bad) {
            cout << "Case " << kase++ << ": " << "YES\n";
        } else {
            cout << "Case " << kase++ << ": " << "NO\n";
        }
    }
    return 0;
}