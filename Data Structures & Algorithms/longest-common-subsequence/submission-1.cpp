class Solution {
public:
    int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if(i >= text1.size() || j >= text2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int found = 0;
        int notfound = 0;
        if(text1[i] == text2[j]){
            found += solve(text1, text2, i+1, j+1, dp) + 1;
        }
        else {
            notfound = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }
        return dp[i][j] = max(found, notfound);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1, vector<int>(n2, -1));

        return solve(text1, text2, 0, 0, dp);
    }
};
