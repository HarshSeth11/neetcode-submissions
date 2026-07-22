class Solution {
public:
    int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int ans = 0;

    void bfs(vector<vector<int>>& grid, int i, int j) {
        int temp = 1;
        queue<pair<int, int>> q;
        q.push({i,j});        

        grid[i][j] = 0;

        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for(int k=0; k<4; k++) {
                int newx = x+dir[k][0];
                int newy = y+dir[k][1];

                if(newx >= 0 && newy >= 0 && newx < grid.size() && newy < grid[0].size() && grid[newx][newy] == 1) {
                    grid[newx][newy] = 0;
                    q.push({newx, newy});
                    temp++;
                }
            }
        }
        ans = max(temp, ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
