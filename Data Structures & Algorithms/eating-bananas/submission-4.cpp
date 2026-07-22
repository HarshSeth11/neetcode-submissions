class Solution {
public:
    bool check(vector<int>& piles,int h,int k) {
        int totalHours = 0;

        for(int i=0; i<piles.size(); i++) {
            totalHours += (piles[i] + k - 1) / k;
            if(totalHours > h) return false;
        }

        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());

        int lowerbound = 1;
        int upperbound = maxi;

        int ans = upperbound;

        while(lowerbound <= upperbound) {
            int mid = lowerbound + (upperbound-lowerbound)/2;

            if(check(piles, h, mid)) {
                ans = min(ans, mid);
                upperbound = mid-1;
            }
            else {
                lowerbound = mid+1;
            }
        }

        return ans;
    }
};
