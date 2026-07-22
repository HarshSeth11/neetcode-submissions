class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string& s, int x, int y) {
        int i=x;
        int j=y;

        while(i<=j) {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(string& s, int start, vector<string>& temp) {
        if(start == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int end=start; end<s.size(); end++) {
            if(isPal(s, start, end)) {
                temp.push_back(s.substr(start, end - start + 1));
                solve(s, end+1, temp);
                temp.pop_back();
            }
            // else solve(s, end+1, temp);
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s, 0, temp);
        return ans;
    }
};
