class Solution {
private:
    set<vector<int>> st;
public:
    void solve(vector<int>& nums, int i, int target, int sum, vector<int>& temp) {
        if(sum == target) {
            st.insert(temp);
            return;
        }
        else if(sum > target) return;
        if(i == nums.size()) return;

        solve(nums, i+1, target, sum, temp);

        temp.push_back(nums[i]); 
        sum += nums[i];
        solve(nums, i, target, sum, temp);
        solve(nums, i+1, target, sum, temp);

        // backtrack
        int back = temp.back();
        temp.pop_back();
        sum -= back;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(nums, 0, target, 0, temp);
        vector<vector<int>> ans;

        for(auto i : st) {
            temp = {};
            for(int j : i) {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
