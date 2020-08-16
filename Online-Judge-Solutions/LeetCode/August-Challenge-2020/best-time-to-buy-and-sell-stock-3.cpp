class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        
        vector <vector <vector <int> > > dp(n + 1, vector <vector <int> > (2, vector <int> (3, -1)));
        
        function <int(int, int, int)> solve = [&](int item, int what, int cnt) {
            if (item == n || cnt == 2) return 0;
            if (dp[item][what][cnt] != -1) return dp[item][what][cnt];
            
            int ret = solve(item + 1, what, cnt);
            
            if (what == 0) ret = max(ret, solve(item + 1, 1, cnt) - prices[item]);
            else ret = max(ret, solve(item + 1, 0, cnt + 1) + prices[item]);
            
            return dp[item][what][cnt] = ret;    
        };
        return solve(0, 0, 0);
    }
};
