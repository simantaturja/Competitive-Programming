class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = (int)grid.size(), col = (int)grid[0].size();
        vector <vector <int> > visited(row+1, vector <int>(col+1, 0));
        queue <pair <pair <int, int>, int> > rotten;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        vector <int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
        
        int ans = 0;
        while (!rotten.empty()) {
            pair <int, int> p = rotten.front().first; 
            int m = rotten.front().second; rotten.pop();
            ans = max(ans, m);
            for (int i = 0; i < 4; ++i) {
                int cx = p.first + dx[i], cy = p.second + dy[i];
                if (cx >= 0 && cy >= 0 && cx < row && cy < col && visited[cx][cy] == 0 && grid[cx][cy] != 0) {
                    visited[cx][cy] = 1;
                    rotten.push({{cx, cy}, m + 1});
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    ans = -1;
                    break;
                }
            }
            if (ans == -1) break;
        }
        return ans;
    }
};