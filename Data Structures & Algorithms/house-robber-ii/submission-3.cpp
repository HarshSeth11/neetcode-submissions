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
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        vector<int> first(nums.begin()+1, nums.end());
        vector<int> second(nums.begin(), nums.end()-1);

        return max(decideStep(first, 0, dp1), decideStep(second, 0, dp2));
    }
};