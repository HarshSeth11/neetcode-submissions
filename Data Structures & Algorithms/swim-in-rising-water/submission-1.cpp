class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0}); // Grid value, maxi, x, y

        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int maxi = top[0];
            int x = top[1];
            int y = top[2];

            if(vis[x][y]) continue;

            vis[x][y] = 1;

            if(x == n-1 && y == m-1) return maxi;
            
            for(int i=0; i<4; i++) {
                int xx = x+dir[i][0];
                int yy = y+dir[i][1];

                if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;

                int temp = max(maxi, grid[xx][yy]);
                pq.push({temp, xx, yy});
            }
        }

        return -1;
    }
};
