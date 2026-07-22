class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (j == p.size())
            return i == s.size();

        if(dp[i][j] != -1) return dp[i][j];

        bool match = (i < s.size() &&
                     (s[i] == p[j] || p[j] == '.'));

        
        if(j + 1 < p.size() && p[j+1] == '*') {
            return dp[i][j] = solve(s, p, i, j+2, dp) ||
             (match && solve(s, p, i+1, j, dp));
        }

        return dp[i][j] = match && solve(s, p, i+1, j+1, dp);
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, 0, 0, dp);
    }
};
// a*d.ef*kl*m
// abcddefghijklm