class Solution {
public:
    string ans = "";
    bool isPalindrome(string s, int st, int en) {
        if(en-st+1 <= 0) return false;
        if(en-st+1 == 1) return true;

        while(st <= en) {
            if(s[st] != s[en]) return false;
            st++;
            en--;
        }

        return true;
    }

    void solve(string s, int st, int en, vector<vector<int>>& dp){
        if(st > en) return;

        if(dp[st][en] != -1) return;

        if(isPalindrome(s, st, en) && ans.size() < (en-st)+1) {
            ans = s.substr(st, (en-st)+1);
            dp[st][en] = 1;
            return;
        }

        dp[st][en] = 0;

        solve(s, st+1, en, dp);
        solve(s, st, en-1, dp);
    }
    string longestPalindrome(string s) {
        int n = s.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        solve(s, 0, n, dp);
        return ans;
    }
};
