class Solution {
public:
    int solve(vector<int>& nums, int target, int idx) {
        if(idx == nums.size() && target == 0) return 1;
        if(idx >= nums.size()) return 0;

        return solve(nums, target-nums[idx], idx+1) + solve(nums, target+nums[idx], idx+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0);
    }
};
