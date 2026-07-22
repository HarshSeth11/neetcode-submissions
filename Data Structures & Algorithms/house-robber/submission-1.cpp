class Solution {
public:
    int decideStep(vector<int>& nums, int i, vector<int>& dp) {
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        dp[i] = max(decideStep(nums, i+2, dp),decideStep(nums, i+3, dp)) + nums[i];
        return dp[i];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);
        return max(decideStep(nums, 0, dp), decideStep(nums, 1, dp));
    }
};
