class Solution {
private:
    vector<vector<int>> ans;
public:
    void solve(vector<int>& nums, int i, int target, int sum, vector<int>& temp) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        else if(sum > target) return;
        if(i == nums.size()) return;

        solve(nums, i+1, target, sum, temp);

        temp.push_back(nums[i]); 
        sum += nums[i];
        solve(nums, i, target, sum, temp);

        // backtrack
        int back = temp.back();
        temp.pop_back();
        sum -= back;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(nums, 0, target, 0, temp);
        
        return ans;
    }
};
