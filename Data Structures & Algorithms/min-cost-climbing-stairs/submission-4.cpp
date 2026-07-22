class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[n-1];
        int second = cost[n-2];

        for(int i=n-3; i>=0; i--) {
            int temp = cost[i] + min(first, second);
            first = second;
            second = temp;
        }

        return min(first, second);
    }
};
// [4,5,3,3,2,1,1]