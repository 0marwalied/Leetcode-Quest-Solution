class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

        int ans = 0;
        const int n = grid.size(), m = grid[0].size();
        int r = -1, c = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && r == -1) {
                    r = i, c = j;
                }
            }
        }
        queue<vector<int>>q;
        q.push({r, c});
        vector<vector<bool>>vis(n, vector<bool>(m));

        auto isValied = [&](int x, int y)->bool{
            return 0 <= x && x < n && 0 <= y && y < m && grid[x][y];
        };


        while (!q.empty()) {
            vector<int>pos = q.front(); q.pop();
            int x = pos[0], y = pos[1];
            vis[x][y] = true;
            for (int d = 0; d < 4; d++) {
                int nx = dx[d] + x, ny = dy[d] + y;
                if (isValied(nx, ny)) {
                    if (!vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};