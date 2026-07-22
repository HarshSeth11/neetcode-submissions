class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string token : tokens) {
            if(token == "+" || token == "-" ||
   token == "*" || token == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                if(token == "+") st.push(second+first);
                else if(token == "-") st.push(second-first);
                else if(token == "*") st.push(second*first);
                else if(token == "/") st.push(second/first);
            }
            else{
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
