class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;

        int carry = 0;
        int n = digits.size();
        for(int i=n-1; i>=0; i--) {
            int sum = carry + digits[i];
            if(i == n-1) sum += 1;
            carry = 0;
            if(sum > 9) {
                int lastDigit = sum%10;
                carry = sum/10;
                ans.push_back(lastDigit);
            }
            else ans.push_back(sum);
        }
        if(carry) {
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
