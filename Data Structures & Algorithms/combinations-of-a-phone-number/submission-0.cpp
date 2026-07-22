class Solution {
public:
    vector<string> ans;

    void helper(string& digits, vector<string>& dtoc, string& temp, int start) {
        if(start >= digits.size()) {
            ans.push_back(temp);
            return;
        }

        int digit = digits[start] - '0';
        string chrs = dtoc[digit];

        for(int i=0; i<chrs.size(); i++) {
            temp.push_back(chrs[i]);
            helper(digits, dtoc, temp, start+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> dtoc = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;

        helper(digits, dtoc, temp, 0);

        return ans;        
    }
};
