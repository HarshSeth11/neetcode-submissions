class Solution {
public:
    int solve(string& s, string& t, int i, string temp, map<pair<int, string>, int>& dp) {
        if(i >= s.size()) {
            if(temp == t) return 1;
            else return 0;
        }

        if(dp.find({i, temp}) != dp.end()) return dp[{i,temp}];

        // take
        int take = solve(s, t, i+1, temp+s[i], dp);
        
        // skip
        int skip = solve(s, t, i+1, temp, dp);

        return dp[{i,temp}] = take+skip;
    }
    int numDistinct(string s, string t) {
        map<pair<int, string>, int> dp;
        return solve(s, t, 0, "", dp);
    }
};
