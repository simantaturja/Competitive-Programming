class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int hIndexAns = 0, n = (int)citations.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (n - i <= citations[i]) {
                hIndexAns = max(hIndexAns, n - i);
            } else break;
        }
        return hIndexAns;
    }
};