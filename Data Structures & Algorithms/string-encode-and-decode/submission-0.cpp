class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";
        for(string st : strs) {
            int len = st.size();
            encoded_str += to_string(len) + "#" + st;
        }

        return encoded_str;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> ans;

        while(i < s.size()) {
            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j-i));

            j += 1;

            string st = s.substr(j, len);

            ans.push_back(st);

            i = j+len;
        }

        return ans;
    }
};
