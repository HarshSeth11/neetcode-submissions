class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        for(int i=0; i<s.size(); i++) {
            arr1[s[i]-'a']++;
        }
        for(int i=0; i<t.size(); i++) {
            arr2[t[i]-'a']++;
        }

        return arr1 == arr2;
    }
};
