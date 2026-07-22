class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size+2, vector<int>(2, 0));
        
        for(int i=size-1; i>=0; i--) {
            for(int hasCoin=0; hasCoin<2; hasCoin++) {
                int sell = 0;
                int buy = 0;
                if(hasCoin) {
                    // sell
                    sell = dp[i+2][!hasCoin] + prices[i];
                }
                else if(!hasCoin) {
                    // buy
                    buy = dp[i+1][!hasCoin] - prices[i];
                }

                int skip = dp[i+1][hasCoin];

                dp[i][hasCoin] = max({sell, skip, buy});
            }
        }

        return dp[0][0];
    }
};
