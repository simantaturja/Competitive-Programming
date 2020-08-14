class Solution {
public:
    int longestPalindrome(string s) {
        
        vector <int> freq(300, 0);
        int n = (int)s.length();
        int distinct = 0;
        for (int i = 0; i < n; ++i) {
            if (freq[s[i]] == 0) ++distinct;
            ++freq[s[i]];
        }
        if (distinct == 1) {
            return n;
        }
        
        int evenSum = 0;
        for (int i = 0; i < n; ++i) {
            if (freq[s[i]] % 2 == 0) {
                evenSum += freq[s[i]];
                freq[s[i]] = 0;
            }
        }
        
        vector <int> cnt;
        for (int i = 0; i < n; ++i) {
            if (freq[s[i]] % 2 != 0) {
                cnt.push_back(freq[s[i]]);
                freq[s[i]] = 0;
            }
        }
        
        int cnt_size = (int)cnt.size();
        if (cnt_size == 0) return evenSum;
        
        sort(cnt.begin(), cnt.end());
        int oddSum = cnt[cnt_size - 1];
        for (int i = 0; i < cnt_size - 1; ++i) oddSum += (cnt[i] - 1);
        return evenSum + oddSum;
    }
};
