class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int node1, int node2) {
        vis[node] = 1;

        for(int nbr : graph[node]) {
            if ((node == node1 && nbr == node2) ||
                (node == node2 && nbr == node1))
            {
                continue;
            }
            if(!vis[nbr]) {
                dfs(nbr, graph, vis, node1, node2);
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> graph(n+1);

        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i=n-1; i>=0; i--) {
            int u = edges[i][0];
            int v = edges[i][1];

            vector<int> vis(n+1,0);

            dfs(1, graph, vis, u, v);
            if(vis[v] && vis[u]) return {u,v};
        }

        return {};
    }
};
