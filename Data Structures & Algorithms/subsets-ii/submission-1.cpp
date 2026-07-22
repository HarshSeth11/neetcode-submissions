class Solution {
private:
    set<vector<int>> ans;

    void helper(vector<int>& nums, int index, vector<int>& temp) {
        ans.insert(temp);

        for(int i=index; i<nums.size(); i++) {

            if(i > index && nums[i-1] == nums[i]) {
                continue;
            }
            // take
            temp.push_back(nums[i]);
            helper(nums, i+1, temp);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        helper(nums, 0, temp);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
