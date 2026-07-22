class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> dependents(numCourses, 0);
        map<int, vector<int>> mp;
        
        for(int i=0; i<prerequisites.size(); i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];

            dependents[x]++;
            mp[y].push_back(x);
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++) {
            if(dependents[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();

            if(mp.find(front) == mp.end()) continue;

            for(int sub : mp[front]) {
                if(--dependents[sub] == 0) q.push(sub);
            }
        }

        for(int i=0; i<numCourses; i++) {
            if(dependents[i] > 0) return false;
        }

        return true;
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
