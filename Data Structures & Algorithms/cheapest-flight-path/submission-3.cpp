class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<pair<int,int>>> graph;
        for(int i=0; i<flights.size(); i++) {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int,int>> pq;
        pq.push({0,src});
        dist[src] = 0; 

        while(!pq.empty() && k >= 0) {
            int size = pq.size();
            while(size--) {
                auto [cost, node] = pq.front();
                pq.pop();


                for(auto [nbr, nbrCost] : graph[node]) {
                    nbrCost = nbrCost+cost;
                    if(nbrCost < dist[nbr]) {
                        dist[nbr] = nbrCost;
                        pq.push({dist[nbr], nbr});
                    }
                }
            }
            k--;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
