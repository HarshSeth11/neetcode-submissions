class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int courseTaken = 0;

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            courseTaken++;

            if(graph[front].size() == 0) continue;

            for(int sub : graph[front]) {
                if(--indegree[sub] == 0) q.push(sub);
            }
        }

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] > 0) return false;
        }

        return courseTaken == numCourses;
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
