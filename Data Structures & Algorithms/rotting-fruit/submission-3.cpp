class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

        int minutes = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [x,y] = q.front();
                q.pop();

                for(int i=0; i<4; i++) {
                    int newx = x+dir[i][0];
                    int newy = y+dir[i][1];
                    if(newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] == 0) continue;
                    
                    if(grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                }
            }
            if(!q.empty())minutes++;
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;
    }
};
