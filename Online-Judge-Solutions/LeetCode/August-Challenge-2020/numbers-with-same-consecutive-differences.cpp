class Solution {
public:
    
    vector<int> numsSameConsecDiff(int N, int K) {
        vector <int> ans;
        if (N == 1) {
            for (int i = 0; i <= 9; ++i) ans.push_back(i);
            return ans;
        }
        set <int> numbers;
        function <int(int)> isKdigit = [&](int val) {
            int len = 0;
            while (val > 0) {
                ++len; val/=10;
            }
            return len;
        };
        function <void (int, int) > solve = [&](int pos, int num) {
            if (pos >= N) {
                if (isKdigit(num) == N) numbers.insert(num);
                return;
            }  
            int last_num = num % 10;
            if (last_num - K >= 0) solve(pos + 1, num * 10 + (last_num - K));
            if (last_num + K <= 9) solve(pos + 1, num * 10 + (last_num + K));
        };
        
        for (int i = 1; i <= 9; ++i) {
            numbers.clear();
            solve(1, i);
            for (int num : numbers) ans.push_back(num);
        }
        return ans;
    }
};
