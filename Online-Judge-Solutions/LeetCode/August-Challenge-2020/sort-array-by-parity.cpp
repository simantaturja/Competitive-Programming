class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector <int> ans;
        for (int num : A) {
            if (num % 2 == 0) ans.push_back(num);
        }
        for (int num : A) {
            if (num % 2 != 0) ans.push_back(num);
        }
        return ans;
    }
};
