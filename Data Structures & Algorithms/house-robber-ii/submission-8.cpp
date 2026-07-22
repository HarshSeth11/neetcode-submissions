class Solution {
public:
    int solve(vector<int>& nums, int st, int en) {
        int next2 = 0;
        int next1 = 0;

        for(int i=en-1; i>=st; i--) {
            int temp = max(nums[i]+next2, next1);
            next2 = next1;
            next1 = temp;
        }

        return next1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(solve(nums, 0, n-1), solve(nums, 1, n));
    }
};
