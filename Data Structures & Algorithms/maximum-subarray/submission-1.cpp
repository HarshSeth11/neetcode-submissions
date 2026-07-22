class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            for(int j=i; j<nums.size(); j++) {
                int sum = 0;
                for(int k=i; k<=j; k++) {
                    sum += nums[k];
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};
