class Solution {
private:
    vector<vector<int>> ans;
public:
    void helper(int i, vector<int>& nums, vector<int>& temp) {
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // not take 
        helper(i+1, nums, temp);

        // take
        temp.push_back(nums[i]);
        helper(i+1, nums, temp);

        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(0, nums, temp);

        return ans;
    }
};
