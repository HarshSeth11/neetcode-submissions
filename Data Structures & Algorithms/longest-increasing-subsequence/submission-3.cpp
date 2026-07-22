class Solution {
public:
    int solve(vector<int>& nums, int num, int i, vector<vector<int>>& dp) {
        if(i >= nums.size()) return 0;

        if(dp[num+1][i] != -1) return dp[num+1][i];

        // take it
        int take = 0;
        if(num == -1 || nums[i] > nums[num]) take = solve(nums, i, i+1, dp) + 1;

        // skip
        int skip = solve(nums, num, i+1, dp);

        dp[num+1][i] = max(take, skip);
        return dp[num+1][i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n, -1));
        return solve(nums, -1, 0, dp);
    }
};
