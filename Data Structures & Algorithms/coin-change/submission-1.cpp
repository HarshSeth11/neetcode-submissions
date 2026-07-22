class Solution {
public:
    int solve(vector<int>& coins, int amount, int curr) {
        if(curr < 0 || amount < 0) return INT_MAX/2;
        if(amount == 0) return 0;

        return min(1+solve(coins, amount-coins[curr], curr), solve(coins, amount, curr-1));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int res = solve(coins, amount, n-1);
        return  res>= INT_MAX/2 ? -1 : res;
    }
};
