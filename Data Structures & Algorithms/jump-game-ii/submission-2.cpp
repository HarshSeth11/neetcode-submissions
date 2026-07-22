class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int furthest = 0;
        int currEnd = 0;
        int ans = 0;

        for(int i=0; i<nums.size()-1; i++) {
            furthest = max(furthest, i+nums[i]);

            if(currEnd == i){
                ans++;
                currEnd = furthest;
            }
        }

        return ans;
    }
};
