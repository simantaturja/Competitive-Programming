class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                str += (ch + 32);
            } else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
                str += ch;
            }
        }
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        return (str == rev_str);
    }
};