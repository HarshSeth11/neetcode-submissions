class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> pq;

        int time = 0;

        for(char c : tasks) {
            freq[c-'A']++;
        }

        for(int i=0; i<26; i++) {
            if(freq[i] > 0) pq.push(freq[i]);
        }

        while(!pq.empty()) {
            vector<int> temp;
            int cycle = n+1;

            int pq_size = pq.size();
            
            while(cycle > 0 && !pq.empty()) {
                int freq = pq.top();

                pq.pop();

                freq--;

                if(freq > 0) temp.push_back(freq);

                cycle--;
            }

            for(int i : temp) {
                pq.push(i);
            }

            if(pq.empty()) {
                time += pq_size;
            }
            else time += n+1;
        }

        return time;
    }
};

// A - 3, B - 1, C - 1    // n=2
// 1 Cycle = n+1 = 3

// vector<int> ans;
// A - 2, B - 0, C - 0
// for i=0 to 3{
    // A, B, C, _, A, _, _, _, A
// }