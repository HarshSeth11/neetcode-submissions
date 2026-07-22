// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;

//         for(string key : strs) {
//             string temp = key;
//             sort(temp.begin(), temp.end());
//             mp[temp].push_back(key);
//         }

//         vector<vector<string>> ans;
//         for(auto key : mp) {
//             ans.push_back(key.second);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string key : strs) {
            vector<int> freq(26,0);

            for(char c : key) {
                freq[c-'a']++;
            }

            string unique = "";

            for(int i=0; i<26; i++) {
                unique += "#" + to_string(freq[i]);
            }

            mp[unique].push_back(key);
        }

        vector<vector<string>> ans;
        for(auto key : mp) {
            ans.push_back(key.second);
        }

        return ans;
    }
};

