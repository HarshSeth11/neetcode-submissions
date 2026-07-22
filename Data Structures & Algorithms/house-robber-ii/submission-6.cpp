class Solution {
public:
    int solve(vector<int>& nums, int st, int en) {
        vector<int> dp(nums.size()+2, -1);
        dp[en+1] = 0;
        dp[en] = 0;

        for(int i=en-1; i>=0; i--) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }

        return dp[st];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solve(nums, 0, n-1), solve(nums, 1, n));
    }
};
