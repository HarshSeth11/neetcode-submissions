class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(int i=0; i<times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            graph[u].push_back({v,w});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> weights(n+1, INT_MAX);
        pq.push({0, k});
        weights[k] = 0;

        while(!pq.empty()) {
            auto [w, node] = pq.top();
            pq.pop();

            for(auto [nbr, nbrW] : graph[node]) {
                if(w + nbrW < weights[nbr]) {
                    weights[nbr] = w + nbrW;
                    pq.push({weights[nbr], nbr});
                }
            }
        }

        int ans = 0;

        for(int i=1; i<=n; i++) {
            if(weights[i] == INT_MAX) return -1;
            ans = max(ans, weights[i]);
        }

        return ans;
    }
};
