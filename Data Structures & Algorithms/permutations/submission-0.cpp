class Solution {
public:
    void helper(vector<int>& nums, int index, vector<vector<int>>& ans) {
        if(index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j=index; j < nums.size(); j++) {
            swap(nums[index], nums[j]);
            helper(nums, index+1, ans);
            swap(nums[index], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums, 0, ans);
        return ans;
    }
};
