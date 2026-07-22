class Solution {
public:
    int solve(vector<int>& coins, int amount, int curr, vector<vector<int>>& dp) {
        if(curr < 0 || amount < 0) return INT_MAX/2;
        if(amount == 0) return 0;

        if(dp[curr][amount] != -1) return dp[curr][amount];

        dp[curr][amount] = min(1+solve(coins, amount-coins[curr], curr, dp), solve(coins, amount, curr-1, dp));
        return dp[curr][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res = solve(coins, amount, n-1, dp);
        return  res>= INT_MAX/2 ? -1 : res;
    }
};
