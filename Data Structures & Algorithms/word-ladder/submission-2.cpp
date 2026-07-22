class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        unordered_map<string, vector<string>> patterns;
        wordList.push_back(beginWord);
        for(string s : wordList) {
            for(int i=0; i<s.size(); i++) {
                string pattern = s;
                pattern[i] = '*';

                patterns[pattern].push_back(s);
            }
        }

        queue<string> q;
        unordered_set<string> vis;
        q.push(beginWord);
        vis.insert(beginWord);

        int level = 1;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                string front = q.front();
                q.pop();

                if(front == endWord) return level;

                vector<string> tempPatterns;
                for(int i=0; i<front.size(); i++) {
                    string pattern = front;
                    pattern[i] = '*';

                    tempPatterns.push_back(pattern);
                }

                for(string s : tempPatterns){
                    cout<<s<<endl;
                    for(string nbr : patterns[s]) {
                        
                        if(vis.find(nbr) == vis.end()) {
                            q.push(nbr);
                            vis.insert(nbr);
                        }
                    }
                    patterns[s].clear();
                }
            }

            level++;
        }

        return 0;
    }
};
