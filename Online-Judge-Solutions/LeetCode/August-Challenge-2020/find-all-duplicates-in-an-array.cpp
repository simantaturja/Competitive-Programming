class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = (int)nums.size();
        vector <int> hashTable(n + 1, 0);
        for (int num : nums) {
            ++hashTable[num];
        }
        vector <int> ans;
        for (int num : nums) {
            if (hashTable[num] > 1) {
                ans.push_back(num);
                hashTable[num] = 0;
            }
        }
        return ans;
    }
};