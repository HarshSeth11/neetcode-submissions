class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        for(int i=0; i<n; i++) {
            dp[i][0] = 0;
        }

        for(int i=0; i<n; i++) {
            for(int j=1; j<=amount; j++) {
                int take = INT_MAX/2;

                if(j >= coins[i]) {
                    take = dp[i][j-coins[i]];
                }

                int skip = INT_MAX/2;

                if(i > 0)
                    skip = dp[i-1][j];

                dp[i][j] = min(take+1, skip);
            }
        }

        int mini = INT_MAX;

        for(int i=0; i<n; i++) {
            mini = min(mini, dp[i][amount]);
        }

        return  mini>= INT_MAX/2 ? -1 : mini;
    }
};
