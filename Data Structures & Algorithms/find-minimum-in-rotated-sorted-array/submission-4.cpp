class Solution {
public:
    int findMin(vector<int> &nums) {
        int ans = nums[0];

        int l = 0;
        int r = nums.size()-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[l] <= nums[mid]) {
                ans = min(ans, nums[l]);
                l = mid+1;
            }
            else {
                cout<<mid<<endl;
                ans = min(ans, nums[mid]);
                r = mid-1;
            }
        }

        return ans;
    }
};
