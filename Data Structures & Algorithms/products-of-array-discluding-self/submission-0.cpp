class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre = nums;
        vector<int> post = nums;

        for(int i=1; i<nums.size(); i++) {
            pre[i] *= pre[i-1];
        }

        
        for(int i=nums.size()-2; i>=0; i--) {
            post[i] *= post[i+1];
        }

        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            int prod = 1;
            if(i > 0) prod *= pre[i-1];
            if(i < nums.size()-1) prod *= post[i+1];
            ans.push_back(prod);
        }

        return ans;
    }
};
