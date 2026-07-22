class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    q.push({i,j});
                    board[i][j] = 'Y';
                }
            }
        }

        int dir[4][2] = {{1,0}, {0,1}, {0,-1}, {-1,0}};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int xx = x+dir[i][0];
                int yy = y+dir[i][1];

                if(xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] != 'O') continue;
                board[xx][yy] = 'Y';
                q.push({xx,yy});
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
