class Solution {
public:
    string singleDigitMul(string num1, int num) {
        string s = "";
        int carry = 0;
        for(int i=num1.size()-1; i>=0; i--) {
            int product = ((num1[i]-'0') * num) + carry;
            carry = 0;
            if(product > 9) {
                carry = product/10;
                product = product % 10;
            }
            s += to_string(product);
        }

        if(carry > 0) s += to_string(carry);

        reverse(s.begin(), s.end());

        return s;
    }
    string sumTwoString(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        string ans = "";
        int carry = 0;

        while(i >= 0 && j >= 0) {
            int sum = (num1[i]-'0') + (num2[j]-'0') + carry;
            carry = 0;
            if(sum > 9) {
                sum = sum%10;
                carry = 1;
            }
            ans += to_string(sum);
            i--;
            j--;
        }

        while(i >= 0) {
            int sum = (num1[i]-'0') + carry;
            carry = 0;
            if(sum > 9) {
                sum = sum%10;
                carry = 1;
            }
            ans += to_string(sum);
            i--;
        }

        while(j >= 0) {
            int sum = (num2[j]-'0') + carry;
            carry = 0;
            if(sum > 9) {
                carry = sum / 10;
                sum %= 10;
            }
            ans += to_string(sum);
            j--;
        }

        if(carry > 0) {
            ans += to_string(carry);
            carry = 0;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        if(num1.size() < num2.size()) {
            swap(num1, num2);
        }

        int size2 = num2.size();

        string ans = "";
        
        for(int i=size2-1; i>=0; i--) {
            int n = num2[i] - '0';

            string s = singleDigitMul(num1, n);
            for(int zeros=0; zeros<size2-1-i; zeros++) {
                s += "0";
            }
            cout<<s<<endl;
            ans = sumTwoString(ans, s);
        }

        return ans;
    }
};
