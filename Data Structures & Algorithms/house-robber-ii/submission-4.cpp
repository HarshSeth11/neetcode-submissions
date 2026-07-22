class Solution {
public:
    int decideStep(vector<int>& nums, int st, int en, vector<int>& dp) {
        if(st >= en) return 0;

        if(dp[st] != -1) return dp[st];

        int rob = decideStep(nums, st+2, en, dp) + nums[st];
        int skip = decideStep(nums, st+1, en, dp);

        dp[st] = max(rob, skip);
        return dp[st];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(decideStep(nums, 0, n-1, dp1), decideStep(nums, 1, n, dp2));
    }
};