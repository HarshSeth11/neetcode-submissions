class Solution {
public:
    void helper(vector<int>& nums, int i, vector<int> res, set<vector<int>>& st) {
        if(i == nums.size()) return;
        
        // not take
        helper(nums, i+1, res, st);

        // take
        res.push_back(nums[i]);
        helper(nums, i+1, res, st);

        st.insert(res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        set<vector<int>> st;

        vector<vector<int>> ans;
        ans.push_back({});


        helper(nums, i, {}, st);

        for(auto s : st) {
            vector<int> temp;
            for(int i : s) {
                temp.push_back(i);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
