class Solution {
public:
    int dfs(int i, string& s, vector<int>& dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        dp[i] = dfs(i + 1, s, dp);
        if (i < s.size() - 1) {
            if (s[i] == '1' ||
               (s[i] == '2' && s[i + 1] < '7')) {
                dp[i] += dfs(i + 2, s, dp);
            }
        }
        return dp[i];
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return dfs(0, s, dp);
    }
};

// "121"