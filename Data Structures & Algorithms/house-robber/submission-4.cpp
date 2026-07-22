class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2, -1);
        int next1 = 0;
        int next2 = 0;

        for(int i=n-1; i>=0; i--) {
            int temp = max(nums[i]+next2, next1);
            next2 = next1;
            next1 = temp;
        }

        return next1;        
    }
};
