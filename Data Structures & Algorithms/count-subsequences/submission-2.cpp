class Solution {
public:
    int solve(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if(i >= s.size()) {
            if(j >= t.size()) return 1;
            else return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // take
        int take = 0;
        if(s[i] == t[j]) {
            take = solve(s, t, i+1, j+1, dp);
        }
        
        // skip
        int skip = solve(s, t, i+1, j, dp);

        return dp[i][j] = take+skip;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m+1, -1));
        return solve(s, t, 0, 0, dp);
    }
};
