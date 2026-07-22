class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        queue<int> q;
        
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                q.push(i);
                vis[i] = 1;
                components++;

                while(!q.empty()){
                    int node= q.front();
                    q.pop();

                    for(int nbr : graph[node]) {
                        if(vis[nbr]) continue;

                        vis[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
            
        }

        return components;
    }
};
