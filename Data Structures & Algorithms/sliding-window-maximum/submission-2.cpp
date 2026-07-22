class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start = 0;
        deque<int> dq;

        int maxi = 0;
        int window = 0;
        vector<int> ans;

        for(int end=0; end<nums.size(); end++) {
            while(!dq.empty() && dq.front() <= end-k) dq.pop_front();

            if(!dq.empty() && nums[dq.front()] < nums[end]) {
                dq.pop_front();
                dq.push_front(end);
            }
            else {
                while(!dq.empty() && nums[dq.back()] < nums[end]) {
                    dq.pop_back();
                }
                dq.push_back(end);
            }

            if(end-start+1 == k) {
                ans.push_back(nums[dq.front()]);
                start++;
            }
        }

        return ans;
    }
};
