class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size+2, vector<int>(2, 0));
        
        for(int i=size-1; i>=0; i--) {
            for(int hasCoin=0; hasCoin<2; hasCoin++) {
                if(hasCoin)
                {
                    dp[i][1] =
                        max(
                            prices[i] + dp[i+2][0],
                            dp[i+1][1]
                        );
                }
                else
                {
                    dp[i][0] =
                        max(
                            -prices[i] + dp[i+1][1],
                            dp[i+1][0]
                        );
                }
            }
        }

        return dp[0][0];
    }
};
