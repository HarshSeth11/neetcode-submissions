class Solution {
private:
    set<vector<int>> ans;

    void helper(vector<int>& nums, int i, vector<int>& temp) {
        if(i >= nums.size()) {
            ans.insert(temp);
            return;
        }

        // take
        temp.push_back(nums[i]);
        helper(nums, i+1, temp);
        temp.pop_back();

        // not take
        helper(nums, i+1, temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(nums, 0, temp);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
