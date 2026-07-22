class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;

        int start = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int end = 0; end < s.size(); end++) {

            mp[s[end]]++;

            maxFreq = max(maxFreq, mp[s[end]]);

            int windowLen = end - start + 1;

            // Invalid window
            if(windowLen - maxFreq > k) {

                mp[s[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};