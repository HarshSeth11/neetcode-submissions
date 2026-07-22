class Solution {
public:
    int check(vector<int>& piles,int h,int k) {
        if(k == 0) return false;
        int totalHours = 0;

        for(int i=0; i<piles.size(); i++) {
            totalHours += (piles[i]/k);
            if(piles[i]%k > 0) totalHours += 1;
        }

        cout<<"Total Hours: "<<totalHours<<endl;

        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        if(size == 0) return 0;
        int maxi = *max_element(piles.begin(), piles.end());
        int mini = *min_element(piles.begin(), piles.end());

        int lowerbound = mini/(h/size);
        int upperbound = maxi/(h/size)+1;


        cout<<lowerbound<<endl;
        cout<<upperbound<<endl;

        int ans = upperbound;

        while(lowerbound <= upperbound) {
            int mid = lowerbound + (upperbound-lowerbound)/2;

            cout<<"Mid: "<<mid<<endl;
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
