class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(int i=0; i<t.size(); i++) {
            mp1[t[i]]++;
        }

        int start = 0;
        int required = 0;
        int end = 0;
        
        string ans = "";

        for(;end<s.size(); end++) {
            mp2[s[end]]++;

            if(mp1.find(s[end]) != mp1.end() && mp2[s[end]] <= mp1[s[end]]) required++;

            while(required == t.size()) {
                if(ans == "") ans = s.substr(start, end-start+1);
                else if(ans.size() > end-start+1) ans = s.substr(start, end-start+1);
                mp2[s[start]]--;

                if(mp1.find(s[start]) != mp1.end() &&
                mp2[s[start]] < mp1[s[start]]) {
                    required--;
                }

                start++;
            }
        }

        return ans;
    }
};
