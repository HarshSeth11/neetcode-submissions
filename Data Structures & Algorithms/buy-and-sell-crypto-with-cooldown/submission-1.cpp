class Solution {
public:
    int solve(vector<int>& prices, int idx, bool hasCoin, vector<vector<int>>& dp) {
        if(idx >= prices.size()) {
            return 0;
        }
        if(dp[idx][hasCoin] != -1) return dp[idx][hasCoin];

        int sell = 0;
        int buy = 0;

        if(hasCoin) {
            // sell
            sell = solve(prices, idx+2, !hasCoin, dp) + prices[idx];
        }
        else if(!hasCoin) {
            // buy
            buy = solve(prices, idx+1, !hasCoin, dp) - prices[idx];
        }

        int skip = solve(prices, idx+1, hasCoin, dp);

        return dp[idx][hasCoin] = max({sell, skip, buy});
    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2, -1));
        return solve(prices, 0, false, dp);
    }
};
// 0 -> -1, 0
// 1 -> 2, -1
// 0 -> 0, 0
// 1 -> 3, -1