class Solution {
public:
    int ans = INT_MIN;
    void solve(vector<int>& nums, int i, int maxEnd, int minEnd) {
        if(i >= nums.size()) return;

        int oldMax = maxEnd;
        int oldMin = minEnd;

        maxEnd = max({
            nums[i],
            oldMax*nums[i],
            oldMin*nums[i]
        });

        minEnd = min({
            nums[i],
            oldMax*nums[i],
            oldMin*nums[i]
        });

        solve(nums, i+1, maxEnd, minEnd);

        ans = max(ans, maxEnd);
    }
    int maxProduct(vector<int>& nums) {
        solve(nums, 0, 1, 1);
        return ans;
    }
};
