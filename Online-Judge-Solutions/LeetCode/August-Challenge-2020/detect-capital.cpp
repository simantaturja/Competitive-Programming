class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0, small = 0;
        int n = (int)word.length();
        for (char ch : word) {
            if (ch >= 'A' && ch <= 'Z') ++cap;
            else ++small;
        }
        return (cap == n || small == n || (cap == 1 && word[0] >= 'A' && word[0] <= 'Z'));
    }
}
