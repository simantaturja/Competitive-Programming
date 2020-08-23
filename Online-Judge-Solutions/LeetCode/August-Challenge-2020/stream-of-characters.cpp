class StreamChecker {
public:
    vector <vector <int> > tree, end;
    vector <int> exists;
    int sz;
    string store;
    int store_len;
    StreamChecker(vector<string>& words) {    
        tree.resize(27); end.resize(27); store = "";
        store_len = 0;
        for (int i = 0; i < 27; ++i) tree[i].resize(40020), end[i].resize(40020);
        exists.resize(40020); sz = 0;
        for (string word : words) {
            reverse(word.begin(), word.end());
            int len = (int) word.length();
            int v = 0;
            for (int i = 0; i < len; ++i) { 
                char c = word[i];
                if (!exists[tree[c-'a'][v]]) {
                    sz++;
                    tree[c-'a'][v] = sz;
                    exists[tree[c-'a'][v]] = 1;
                }
                if (i == len - 1) {
                    end[c-'a'][v] = 1;
                }
                v = tree[c-'a'][v];   
            }
        }
    }
    
    bool helper(int in, int v) {
        char c = store[in];
        if (in == 0) {
            return exists[tree[c-'a'][v]] && end[c-'a'][v];
        }
        bool ret = 0;
        if (exists[tree[c-'a'][v]]) {
            if (end[c-'a'][v]) return true;
            ret = helper(in - 1, tree[c-'a'][v]);
        } else {
            ret = false;
        }
        return ret;
    }
    
    bool query(char letter) {
        store += letter;
        store_len += 1;
        return helper(store_len - 1, 0);
        
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
