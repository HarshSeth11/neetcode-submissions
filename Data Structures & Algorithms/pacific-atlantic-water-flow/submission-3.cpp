class Solution {
public:
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<int>>& vis) {
        int n = heights.size();
        int m = heights[0].size();
        vis[x][y] = 1;

        for(int i=0; i<4; i++) {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];

            if(xx < 0 || yy < 0 || xx >= n || yy >= m || heights[x][y] > heights[xx][yy] || vis[xx][yy] == 1) continue;

            dfs(heights, xx, yy, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || j == 0) {
                    pacific[i][j] = 1;
                    dfs(heights, i, j, pacific);
                }
                if(i == n-1 || j == m-1) {
                    atlantic[i][j] = 1;
                    dfs(heights, i, j, atlantic);
                }
            }
        }


        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
