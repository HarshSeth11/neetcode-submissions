class Solution {
public:
    int dir[4][4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()) {
            pair<int, int> idx = q.front();
            q.pop();

            int x = idx.first;
            int y = idx.second;

            grid[x][y] = '0';
 
            for(int k=0; k<4; k++) {
                int newx = x+dir[k][0];
                int newy = y+dir[k][1];

                if(newx >= 0 && newy >= 0 && newx < grid.size() && newy < grid[0].size() && grid[newx][newy] == '1') {
                    q.push({newx, newy});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    ++ans;
                    bfs(grid, i, j);
                }
            }
        }

        return ans;
    }
};
