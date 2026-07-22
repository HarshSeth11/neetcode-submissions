class Solution {
public:
    int start = -1;
    int maxLen = 0;
    void expand(string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            if(right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();

        for(int i=0; i<n; i++) {
            expand(s, i, i+1);

            expand(s, i, i);
        }

        return s.substr(start, maxLen);
    }
};
