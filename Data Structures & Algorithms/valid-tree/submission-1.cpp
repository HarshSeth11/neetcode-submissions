class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& parent) {
        if(vis[node] == 1) return false;
        vis[node] = 1;

        for(int nbr : graph[node]) {
            if(vis[nbr] == 1 && parent[node] == nbr) continue;
            else if(vis[nbr] == 1 && parent[node] != nbr) return false;
            parent[nbr] = node;
            if(!dfs(nbr, graph, vis, parent)) return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> parent(n, -1);
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
            if(!dfs(i, graph, vis, parent)) return false;
        }

        return true;
    }
};
