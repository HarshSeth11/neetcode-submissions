class Solution {
private:
    vector<vector<int>> ans;
public:
    void solve(vector<int>& nums, int i, int target, vector<int>& temp) {
        if(0 == target) {
            ans.push_back(temp);
            return;
        }
        else if(0 > target) return;
        if(i == nums.size()) return;

        solve(nums, i+1, target, temp);

        temp.push_back(nums[i]); 
        target -= nums[i];
        solve(nums, i, target, temp);

        // backtrack
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(nums, 0, target, temp);
        
        return ans;
    }
};
