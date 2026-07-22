class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans(3, INT_MIN);

        for(vector<int> v : triplets) {
            bool flag = true;
            for(int i=0; i<3; i++) {
                if(target[i] < v[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans[0] = max(ans[0], v[0]);
                ans[1] = max(ans[1], v[1]);
                ans[2] = max(ans[2], v[2]);
            }
        }

        return target == ans;
    }
};
