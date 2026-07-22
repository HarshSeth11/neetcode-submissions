class Solution {
public:
    void dfs(string node, unordered_map<
            string,
            priority_queue<string, vector<string>, greater<string>>
        >& graph ,vector<string>& ans) {
        while(!graph[node].empty()) {
            string nbr = graph[node].top();
            graph[node].pop();
            dfs(nbr, graph, ans);
        }

        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<
            string,
            priority_queue<string, vector<string>, greater<string>>
        > graph;

        for(auto ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> ans;

        dfs("JFK", graph, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
