class Solution {
public:
    int solve(int amount, vector<int>& coins, int idx, vector<vector<int>>& dp) {
        if(idx >= coins.size()) return 0;
        if(amount < 0) return 0;
        if (amount == 0) return 1;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        return dp[idx][amount] = solve(amount-coins[idx], coins, idx, dp) + solve(amount, coins, idx+1, dp);
    } 

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(amount, coins, 0, dp);
    }
};
