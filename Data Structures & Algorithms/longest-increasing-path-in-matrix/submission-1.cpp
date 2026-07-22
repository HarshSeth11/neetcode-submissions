class Solution {
private:
    int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
public:
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(row >= n || col >= m) return 0;

        if(dp[row][col] != -1) return dp[row][col];

        int ans = 1;

        for(int k=0; k<4; k++) {
            int xx = row+dir[k][0];
            int yy = col+dir[k][1];
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if(matrix[xx][yy] > matrix[row][col]) {
                ans = max(ans, solve(matrix, xx, yy, dp) +1);
            }
        }

        return dp[row][col] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, solve(matrix, i, j, dp));
            }
        }
        return ans;
    }
};
