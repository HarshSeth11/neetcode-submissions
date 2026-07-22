class Solution {
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>>& dp) {
        if(i >= word1.size()) return word2.size() - j > 0 ? word2.size() - j : 0;
        if(j >= word2.size()) return word1.size() - i;

        if(dp[i][j] != -1) return dp[i][j];
 
        if(j < word2.size() && word1[i] == word2[j]) {
            return dp[i][j] = solve(word1, word2, i+1, j+1, dp);
        }
        else {
            int insert = solve(word1, word2, i, j+1, dp)+1;

            int del = solve(word1, word2, i+1, j, dp)+1;

            int replace = solve(word1, word2, i+1, j+1, dp)+1;

            return dp[i][j] = min({insert, del, replace});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};
