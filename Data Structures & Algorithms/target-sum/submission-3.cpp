class Solution {
public:
    int sum = 0;
    int solve(vector<int>& nums, int target, int idx, map<pair<int,int>,int>& dp) {
        if(idx == nums.size() && target == 0) return 1;
        if(idx >= nums.size()) return 0;

        if(dp.find({idx,target}) != dp.end()) return dp[{idx,target}];

        return dp[{idx, target}] = solve(nums, target-nums[idx], idx+1, dp) + solve(nums, target+nums[idx], idx+1, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int,int>, int> dp;
        return solve(nums, target, 0, dp);
    }
};
