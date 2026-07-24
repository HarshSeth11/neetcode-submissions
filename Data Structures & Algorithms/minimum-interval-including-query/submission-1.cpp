class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();

        sort(intervals.begin(), intervals.end());

        vector<pair<int,int>> queries_idx;
        for (int i = 0; i < m; i++) {
            queries_idx.push_back({queries[i], i});
        }

        sort(queries_idx.begin(), queries_idx.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> ans(m, -1);
        int i = 0;

        for(auto query : queries_idx) {
            while(i < n && intervals[i][0] <= query.first) {
                pq.push({intervals[i][1]-intervals[i][0]+1, intervals[i][0], intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top()[2] < query.first)
                pq.pop();

            if(pq.empty()) continue;
            ans[query.second] = pq.top()[0];
        }

        return ans;
    }
};
