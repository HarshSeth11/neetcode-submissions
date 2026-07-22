class Solution {
public:
    int decideStep(vector<int>& nums, int i, vector<int>& dp) {
        if(i >= nums.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int rob = decideStep(nums, i+2, dp) + nums[i];
        int skip = decideStep(nums, i+1, dp);

        dp[i] = max(rob, skip);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, -1);
        return decideStep(nums, 0, dp);
    }
};
