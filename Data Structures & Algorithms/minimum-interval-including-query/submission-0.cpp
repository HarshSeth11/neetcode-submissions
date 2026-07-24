class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, int> mp;
        for(int i : queries) {
            mp[i] = INT_MAX;
        }

        for(auto interval : intervals) {
            for(int i : queries) { 
                int len = interval[1] - interval[0] + 1;
                if(interval[0] <= i && i <= interval[1]) {
                    mp[i] = min(mp[i], len);
                }
            }
        }

        vector<int> ans;
        for(int i : queries) {
            if(mp[i] == INT_MAX) {
                ans.push_back(-1);
            }
            else ans.push_back(mp[i]);
        }

        return ans;
    }
};
