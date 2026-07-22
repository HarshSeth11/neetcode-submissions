class Solution {
public:
    bool solve(vector<int>& nums, int idx, int sum, vector<vector<int>>& dp) {
        if(sum == 0) return true;
        if(idx >= nums.size() || sum < 0) return false;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        // take
        bool left = solve(nums, idx+1, sum-nums[idx], dp);

        // skip
        bool right = solve(nums, idx+1, sum, dp);

        return dp[idx][sum] = left || right;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1));

        if(sum%2 != 0) return false;

        return solve(nums, 0, sum/2, dp);
    }
};
