class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> mp;
        
        for(int i=0; i<s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        vector<int> ans;

        for(int i=0; i<s.size(); i++) {
            int maxLen = mp[s[i]].back();
            int j;

            for(j=i+1; j<=maxLen; j++) {
                maxLen = max(mp[s[j]].back(), maxLen);
            }
            cout<<"j : "<<j<<", i : "<<i<<endl;
            cout<<"maxLen : "<<maxLen<<endl;
            ans.push_back(maxLen-i+1);
            i = j-1;
        }

        return ans;
    }
};
