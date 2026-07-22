class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string key : strs) {
            string temp = key;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(key);
        }

        vector<vector<string>> ans;
        for(auto key : mp) {
            ans.push_back(key.second);
        }

        return ans;
    }
};
