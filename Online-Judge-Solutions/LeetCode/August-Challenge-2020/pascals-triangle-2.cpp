class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> v;
        v.push_back(1);
        if (rowIndex == 0) return v;
        else if (rowIndex == 1) {
            v.push_back(1);
            return v;
        }
        v.pop_back();
        vector <vector <int> > ans;
        ans.push_back(v);
        v.push_back(1);
        ans.push_back(v);
        for (int i = 2; i <= rowIndex+1; ++i) {
            v.clear();
            v.push_back(1);
            for (int j = 0; j < (int)ans[i - 1].size() - 1; ++j) {
                v.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans[rowIndex+1];
    }
};
