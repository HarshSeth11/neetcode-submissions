class Solution {
public:
    int dir[4][4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int ans = 0;

    void dfs(vector<vector<int>>& grid, int i, int j, int& temp) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
        temp++;
        ans = max(temp, ans);

        grid[i][j] = 0;

        for(int k=0; k<4; k++) {
            dfs(grid, i+dir[k][0], j+dir[k][1], temp);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    int temp = 0;
                    dfs(grid, i, j, temp);
                }
            }
        }
        return ans;
    }
};

// [[0,0,1,0,0,0,0,1,0,0,0,0,0]
// ,[0,0,0,0,0,0,0,1,1,1,0,0,0]
// ,[0,1,1,0,1,0,0,0,0,0,0,0,0]
// ,[0,1,0,0,1,1,0,0,1,0,1,0,0]
// ,[0,1,0,0,1,1,0,0,1,1,1,0,0]
// ,[0,0,0,0,0,0,0,0,0,0,1,0,0]
// ,[0,0,0,0,0,0,0,1,1,1,0,0,0]
// ,[0,0,0,0,0,0,0,1,1,0,0,0,0]]
