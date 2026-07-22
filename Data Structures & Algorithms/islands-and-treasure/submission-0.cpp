class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx < 0 || newy < 0 || newx >= grid.size() || newy >= grid[0].size() || grid[newx][newy] == -1) continue;
                
                if(grid[newx][newy] == INT_MAX) {
                    grid[newx][newy] = grid[x][y]+1;
                    q.push({newx, newy});
                }
            }
        }
    }
};
