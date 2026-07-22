class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }
        int maxi = 0;
        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]-1) != st.end()) continue;

            int temp = nums[i];
            int count = 1;
            while(st.find(temp+1) != st.end()) {
                temp += 1;
                count++;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};
