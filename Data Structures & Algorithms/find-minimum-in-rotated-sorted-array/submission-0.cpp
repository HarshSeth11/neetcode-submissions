class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];
        int l = 0;
        int r = nums.size()-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            ans = min(nums[mid], ans);
            ans = min(ans, nums[l]);
            ans = min(ans, nums[r]);

            if(mid > 0 && nums[mid-1] < nums[mid] && nums[l] > nums[mid]) {
                r = mid-1;
            }
            else l = mid+1;
        }

        return ans;
    }
};
