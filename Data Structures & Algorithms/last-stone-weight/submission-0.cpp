class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0; i<stones.size(); i++) {
            pq.push(stones[i]);
        }

        while(!pq.empty() && pq.size() != 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if(x == y) continue;
            else if(x > y) pq.push(x-y);
            else if(x < y) pq.push(y-x);
        }

        return pq.size() == 1 ? pq.top() : 0;
    }
};
// 2 2 3 4 6
// 2 2 2 3
// 1 2 2
// 1
