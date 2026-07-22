class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int max_freq = 0;

        for(char c : tasks) {
            freq[c-'A']++;
            max_freq = max(max_freq, freq[c-'A']);
        }

        int count_max = 0;
        for(int i=0; i<26; i++) {
            if(max_freq == freq[i]) count_max++;
        }

        int ans = (max_freq-1) * (n+1) + count_max;
        int size = tasks.size();

        return max(size, ans);
    }
};
// A - 3, B - 1, C - 1      // n = 3
// A _ _ _ A _ _ _ A = 9
// A B C _ A _ _ _ A = 9

// A - 3, B - 3, C - 2      // n = 3
// A _ _ _ A _ _ _ A
// A B C _ A B C _ A B

// (3-1) * (3+1) + 1 = 9
// (3-1) * (3+1) + 2 = 10