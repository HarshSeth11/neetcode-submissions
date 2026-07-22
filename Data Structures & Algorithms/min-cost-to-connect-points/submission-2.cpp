class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n,0);
        pq.push({0,0});

        int cost = 0;
        int nodesUsed = 0;

        while(nodesUsed < n) {
            auto front = pq.top();
            pq.pop();

            auto [wt, node] = front;
            
            if(vis[node]) continue;

            vis[node] = 1;

            cost += wt;
            nodesUsed++;

            for(int nbr=0;nbr<n;nbr++) {

                if(vis[nbr])
                    continue;

                int dist =
                    abs(points[node][0]-points[nbr][0]) +
                    abs(points[node][1]-points[nbr][1]);

                pq.push({dist,nbr});
         
            }
        }

        return cost;
    }
};
