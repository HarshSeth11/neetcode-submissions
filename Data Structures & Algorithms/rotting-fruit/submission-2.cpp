class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
            }
        }

        int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};

        int ans = 0;

        while(!q.empty()) {
            auto [x,y] = q.front().first;
            int time = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] == 0) continue;
                
                if(grid[newx][newy] == 1) {
                    grid[newx][newy] = 2;
                    ans = max(time+1, ans);
                    q.push({{newx, newy}, time+1});
                }
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};
