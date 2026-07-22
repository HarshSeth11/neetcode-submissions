class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
        if(state[node] == 1) return false;
        if(state[node] == 2) return true;

        state[node] = 1;

        for(int nbr : graph[node]) {
            if(!dfs(nbr, graph, state)) return false;
        }

        state[node] = 2;

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> state(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];

            graph[y].push_back(x);
        }

        for(int i=0; i<numCourses; i++) {
            if(state[i] == 0) {
                if(!dfs(i, graph, state)) return false;
            }
        }

        return true;
    }
};
