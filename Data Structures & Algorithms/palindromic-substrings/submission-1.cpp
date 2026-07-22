class Solution {
public:
    int ans = 0;
    bool isPal(string s, int st, int en) {
        if(st > en) return false;

        while(st <= en) {
            if(s[st] != s[en]) return false;
            st++;
            en--;
        }

        return true;
    }
    void solve(string s, int st, int en, vector<vector<int>>& dp) {
        if(st > en) return;

        if(dp[st][en] != -1) return;

        if(isPal(s, st, en)) {
            ans++;
            dp[st][en] = 1;
        }

        dp[st][en] = 0;

        solve(s, st+1, en, dp);
        solve(s, st, en-1, dp);
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        solve(s, 0, n-1, dp);
        return ans;
    }
};
