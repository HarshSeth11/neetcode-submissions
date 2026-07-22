class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];

            indegree[x]++;
            graph[y].push_back(x);
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> subjects;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            subjects.push_back(front);

            for(int sub : graph[front]) {
                if(--indegree[sub] == 0) q.push(sub);
            }
        }

        return subjects.size() == numCourses ? subjects : vector<int>();
    }
};
// 0 - 1
// 1 - 1-1=0
// 2 - 1-1 =0
// 4 - 1-1 =0
// 3 -> 2, 4
// 2,4 
// 2 -> 1
// 4,1
// 4 -> 0
// 1-> 0;
// return;
