class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        vector<char> opening = {'{', '[', '('};
        vector<char> closing = {'}', ']', ')'};

        for(char c : s) {
            if(find(opening.begin(), opening.end(), c) != opening.end()) {
                st.push(c);
            }
            else if(find(closing.begin(), closing.end(), c) != closing.end()) {
                if(st.empty()) return false;
                if(st.top() == '(' && c != ')') return false;
                else if(st.top() == '{' && c != '}') return false;
                else if(st.top() == '[' && c != ']') return false;
                st.pop();
            }
        }

        if(!st.empty()) return false;

        return true;
    }
};
