class Solution {
public:
    
    int titleToNumber(string s) {
        int len = (int)s.length();
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans = ans * 26 + (s[i] - 'A') + 1;
        }
        return ans;
    }
};