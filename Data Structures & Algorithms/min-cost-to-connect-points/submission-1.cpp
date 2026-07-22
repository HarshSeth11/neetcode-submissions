class Solution {
public:
    vector<int> parent;

    void DSU(int size) {
        parent.resize(size);

        for(int i=0; i<size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> edges;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                int dist =
                    abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        
        DSU(n);

        int edgesUsed = 0;
        int cost = 0;

        for(auto& front : edges){

            int wt = front[0];
            int u = front[1];
            int v = front[2];

            int pu = find(u);
            int pv = find(v);

            if(pu == pv) continue;

            cout<<" Weight : "<<wt<<", u : "<<u<<", v : "<<v<<endl;

            parent[pv] = pu;

            cost += wt;
            edgesUsed++;

            if(edgesUsed == n-1) return cost;
        }

        return 0;
    }
};
