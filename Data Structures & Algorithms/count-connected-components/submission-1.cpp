class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {
        if(vis[node]) return;

        vis[node] = 1;

        for(int nbr : graph[node]){
            dfs(nbr, graph, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int components = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                components++;

                dfs(i, graph, vis);
            }
            
        }

        return components;
    }
};
