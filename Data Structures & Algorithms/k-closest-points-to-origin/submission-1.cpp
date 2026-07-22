class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<double, vector<int>>,
            vector<pair<double, vector<int>>>,
            greater<pair<double, vector<int>>>
        > pq;
        for(int i=0; i<points.size(); i++) {
            double x = points[i][0];
            double y = points[i][1];

            double distance = sqrt(pow(x,2)+pow(y,2));
            pq.push({distance, points[i]});
        }

        vector<vector<int>> ans;

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
            if(ans.size() == k) break;
        }

        return ans;
    }
};
// [0,2] -> 2
// [2,2] -> 8 -> 2.8