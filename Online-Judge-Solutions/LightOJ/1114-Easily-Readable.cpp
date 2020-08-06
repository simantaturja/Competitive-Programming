#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    
    int tc, kase = 1;
    cin >> tc;
    while (tc--) {
        cout << "Case " << kase++ << ":\n";
        int n;
        cin >> n;
        vector <string> v(n);
        unordered_map <string, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if ((int)v[i].length() > 3) sort(v[i].begin()+1, v[i].end()-1);
            mp[v[i]]++;
        }
        int m;
        cin >> m;
        string str;
        cin.ignore();
        while (m--) {
            getline(cin, str);
            vector <string>words; 
            int len = (int)str.length();
            string word = "";
            for (int i = 0; i < len; ++i) {
                if (str[i] != ' ') {
                    word += str[i];
                } else if (str[i] == ' ') {
                    if((int)word.length() > 0) words.push_back(word);
                    word = "";
                }
            }
            if ((int)word.length() > 0) {
                words.push_back(word);
                word = "";
            }
            
            int ans = 1;
            int w_sz = (int)words.size();
            if (w_sz == 0) {
                cout << 1 << endl;
                continue;
            }
            for (int i = 0; i < w_sz; ++i) {
                string word = words[i];
                if ((int)word.length() > 3) sort(word.begin()+1, word.end()-1);
                ans *= mp[word];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}