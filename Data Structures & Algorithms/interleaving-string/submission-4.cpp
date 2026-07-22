class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp) {
        if(i >= s1.size() && j >= s2.size() && i+j >= s3.size()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(i < s1.size() && s1[i] == s3[i+j]) {
            if(solve(s1, s2, s3, i+1, j, dp)) return dp[i][j] = true;
        }
        if(j < s2.size() && s2[j] == s3[i+j]) {
            if(solve(s1, s2, s3, i, j+1, dp)) return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        
        if(n+m != t) return false;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(s1, s2, s3, 0, 0, dp);
    }
};
