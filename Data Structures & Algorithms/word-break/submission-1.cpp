class Solution {
public:
    bool solve(string s, vector<string>& wordDict, int idx, vector<int>& dp) {
        if(idx >= s.size()) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int i=0; i<wordDict.size(); i++) {
            if(wordDict[i][0] == s[idx]) {
                int size = wordDict[i].size();
                if(s.substr(idx, size) == wordDict[i]) {
                    if(solve(s, wordDict, idx+size, dp)) {
                        dp[idx] = 1;
                        return true;
                    }
                }
            }
        }

        dp[idx] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, wordDict, 0, dp);
    }
};
