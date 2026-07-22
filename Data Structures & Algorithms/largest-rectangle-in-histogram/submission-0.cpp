class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);

        stack<int> leftSt;
        stack<int> rightSt;

        leftSt.push(-1);
        rightSt.push(-1);

        for(int i=0; i<n; i++) {
            if(!leftSt.empty()) {
                while(leftSt.top() != -1 && heights[leftSt.top()] >= heights[i]) leftSt.pop();
                if(leftSt.top() == -1) left[i] = -1;
                else left[i] = leftSt.top();
                leftSt.push(i);
            }
            if(!rightSt.empty()) {
                int j = n-1-i;
                while(rightSt.top() != -1 && heights[rightSt.top()] >= heights[j]) rightSt.pop();
                if(rightSt.top() == -1) right[j] = n;
                else right[j] = rightSt.top();
                rightSt.push(j);
            }
        }

        // Largest Rectangle in Histogram Calculation
        int ans = 0;
        for(int i=0; i<n; i++) {
            int height = heights[i];
            int weidth = right[i] - left[i] - 1;
            int area = height*weidth;

            ans = max(ans, area);
        }

        cout<<"Left : "<<endl;
        for(int i=0; i<n; i++) {
            cout<<left[i]<<" ";
        }
        cout<<endl<<"Right: "<<endl;
        for(int i=0; i<n; i++) {
            cout<<right[i]<<" ";
        }

        return ans;
    }
};
