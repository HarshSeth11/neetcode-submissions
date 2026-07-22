class Solution {
public:
    int sum = 0;
    int solve(vector<int>& nums, int target, int idx, vector<vector<int>>& dp) {
        if(idx == nums.size() && target == 0) return 1;
        if(idx >= nums.size()) return 0;
        if(target < -sum || target > sum)
            return 0;

        if(dp[idx][target+sum] != -1) return dp[idx][target+sum];

        return dp[idx][target+sum] = solve(nums, target-nums[idx], idx+1, dp) + solve(nums, target+nums[idx], idx+1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(
            n,
            vector<int>(2*sum + 1, -1)
        );
        return solve(nums, target, 0, dp);
    }
};
