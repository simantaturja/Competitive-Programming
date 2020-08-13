class CombinationIterator {
public:
    vector <string> combinations;
    int nxt = 0;
    CombinationIterator(string characters, int combinationLength) {
        int n = (int)characters.length();
        string temp = "";
        for (int mask = 0; mask <= (1 << n); ++mask) {
            temp = "";
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    temp += characters[i];
                }
            }
            if ((int)temp.size() == combinationLength) combinations.push_back(temp);
        }
        sort(combinations.begin(), combinations.end());
    }
    
    string next() {
        return combinations[nxt++];
    }
    
    bool hasNext() {
        return nxt < (int)combinations.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
