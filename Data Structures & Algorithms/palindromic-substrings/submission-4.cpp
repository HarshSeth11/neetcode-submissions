class Solution {
public:
    int ans = 0;
    vector<vector<int>> dp;

    bool isPal(string& s, int l, int r){

        if(l>=r)
            return true;

        if(dp[l][r]!=-1)
            return dp[l][r];

        return dp[l][r]=
            s[l]==s[r] &&
            isPal(s, l+1,r-1);
    }
    int countSubstrings(string s) {
        int n = s.size();

        dp.resize(n, vector<int>(n, -1));
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j))
                    ans++;
            }
        }
        return ans;
    }
};
