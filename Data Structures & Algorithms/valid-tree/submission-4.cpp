class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0] = 1;

        while(!q.empty()){
            auto [node, parent] = q.front();
            q.pop();

            for(int nbr : graph[node]) {
                if(parent == nbr) continue;

                if(vis[nbr]) return false;

                vis[nbr] = 1;
                q.push({nbr, node});
            }
        }

        for(int i = 0; i < n; i++) {
            cout<<i<<endl;
            if(!vis[i])
                return false;
        }

        return true;
    }
};
