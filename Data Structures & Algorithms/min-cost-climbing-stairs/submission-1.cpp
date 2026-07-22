class Solution {
public:
    int decideStep(vector<int>& cost, int i, vector<int>& dp) {
        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        dp[i] = min(decideStep(cost, i+1, dp),decideStep(cost, i+2, dp)) + cost[i];
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];
        return min(decideStep(cost, 0, dp), decideStep(cost, 1, dp));
    }
};
