class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for(int i=0; i<t.size(); i++) {
            need[t[i]]++;
        }

        int requirement = 0;
        int start = 0;

        string ans = "";

        for(int end=0; end<s.size(); end++) {
            // put it in the window
            window[s[end]]++;

            // check requirement
            if(need.find(s[end]) != need.end() && window[s[end]] <= need[s[end]]) requirement++;

            while(requirement == t.size()) {
                if(ans == "" || ans.size() > end-start+1) ans = s.substr(start, end-start+1);
                // else if() ans = s.substr(start, end-start+1);
                window[s[start]]--;
                if(need.find(s[start]) != need.end() && window[s[start]] < need[s[start]]) requirement--;
                start++;
            }
        }

        return ans;
    }
};
