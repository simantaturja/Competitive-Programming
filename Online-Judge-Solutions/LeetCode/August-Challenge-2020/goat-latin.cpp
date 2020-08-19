class Solution {
public:
    
    string toGoatLatin(string S) {
        function <char(char)> toLowerCase = [&](char ch) {
            if (ch >= 'A' && ch <= 'Z') return (char)(ch + 32);
            return ch;
        }; 
        
        function <bool(char)> isVowel = [&](char ch) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
            return 0;
        };
        
        vector <string> words;
        int n = (int)S.length();
        string word = "";
        for (int i = 0; i < n; ++i) {
            if (S[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += S[i];
            }
        }
        if ((int)word.size() > 0) words.push_back(word);
        int len_words = (int)words.size();
        string ans = "";
        for (int i = 0; i < len_words; ++i) {
            word = words[i];
            if (isVowel(toLowerCase(word[0]))) {
                words[i] += "ma";
            } else {
                words[i].erase(words[i].begin());
                words[i] += word[0];
                words[i] += "ma";
            }
            for (int j = 0; j <= i; ++j) words[i] += "a";
            ans += words[i];
            if (i != len_words - 1) ans += " ";
        }
        return ans;
    }
};
