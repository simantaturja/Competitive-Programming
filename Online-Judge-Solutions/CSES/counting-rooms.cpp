#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <char> > grid(n + 1, vector <char> (m));
    vector <pair <int, int> > dots;
    vector <vector <bool> > visited(n, vector <bool> (m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                dots.emplace_back(i, j);
            }
        }
    }
    function <bool(int, int)> isValid = [&] (int x, int y) {
        return (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == 0 && grid[x][y] != '#');
    };
    vector <int> dx({0, 0, 1, -1});
    vector <int> dy({1, -1, 0, 0});
    function <void(int, int)> dfs = [&] (int x, int y) {
        visited[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (isValid(nx, ny)) {
                dfs(nx, ny);
            }
        }
    };
    
    int dots_size = (int)dots.size();
    int rooms_cnt = 0;
    for (int i = 0; i < dots_size; ++i) {
        int x = dots[i].first, y = dots[i].second;
        if (visited[x][y] == 0) {
            dfs(x, y);
            ++rooms_cnt;
        }
    }
    cout << rooms_cnt << endl;
    return 0;
}