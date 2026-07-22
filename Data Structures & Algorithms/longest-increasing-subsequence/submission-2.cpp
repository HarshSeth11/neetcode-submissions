class Solution {
public:
    int solve(vector<int>& nums, int num, int i, map<pair<int,int>, int>& dp) {
        if(i >= nums.size()) return 0;

        if(dp.find({num,i}) != dp.end()) return dp[{num,i}];

        // take it
        int take = 0;
        if(nums[i] > num) take = solve(nums, nums[i], i+1, dp) + 1;

        // skip
        int skip = solve(nums, num, i+1, dp);

        dp[{num, i}] = max(take, skip);
        return dp[{num, i}];
    }
    int lengthOfLIS(vector<int>& nums) {
        map<pair<int,int>, int> dp;
        return solve(nums, INT_MIN, 0, dp);
    }
};
