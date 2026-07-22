class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& vis) {
        if(vis[node] == 1) return false;
        vis[node] = 1;

        for(int nbr : graph[node]) {

            if(nbr == parent)
                continue;

            if(vis[nbr])
                return false;

            if(!dfs(nbr, node, graph, vis))
                return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(int i=0; i<n; i++) {
            cout<<vis[i]<<" "<<i<<endl;
            if(vis[i] == 1) continue;
            if(vis[i] == 0 && i != 0) return false;
            if(!dfs(i,-1, graph, vis)) return false;
        }

        return true;
    }
};
