class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int amt=0; amt<=amount; amt++) {
                if(amt-coins[i] >= 0) {
                    dp[i][amt] = dp[i][amt-coins[i]] + dp[i+1][amt];
                }
                else dp[i][amt] = dp[i+1][amt];
            }
        }

        return dp[0][amount];
    }
};
