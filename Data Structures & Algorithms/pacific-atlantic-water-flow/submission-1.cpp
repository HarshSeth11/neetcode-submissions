class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>> pq; // Pacific
        queue<pair<int,int>> aq; // Atlantic

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));


        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i == 0 || j == 0) {
                    pq.push({i,j});
                    pacific[i][j] = 1;
                }
                if(i == n-1 || j == m-1) {
                    aq.push({i,j});
                    atlantic[i][j] = 1;
                }
            }
        }

        while(!pq.empty()) {
            auto [x, y] = pq.front();
            pq.pop();

            int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

            for(int i=0; i<4; i++) {
                int xx = x+dir[i][0];
                int yy = y+dir[i][1];

                if(xx < 0 || yy < 0 || xx >= n || yy >= m || heights[x][y] > heights[xx][yy] || pacific[xx][yy] == 1) continue;

                pacific[xx][yy] = 1;
                pq.push({xx,yy});
            }
        }
        while(!aq.empty()) {
            auto [x, y] = aq.front();
            aq.pop();

            int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

            for(int i=0; i<4; i++) {
                int xx = x+dir[i][0];
                int yy = y+dir[i][1];

                if(xx < 0 || yy < 0 || xx >= n || yy >= m || heights[x][y] > heights[xx][yy] || atlantic[xx][yy] == 1) continue;

                atlantic[xx][yy] = 1;
                aq.push({xx,yy});
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
// P P P P P
// P P P P P
// P . . . .


// . . A . A
// A A A A A
// A A A A A