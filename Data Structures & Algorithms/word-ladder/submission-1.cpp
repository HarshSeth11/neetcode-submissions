class Solution {
public:
    bool compare(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int diff = 0;

        for(int i=0; i<s1.size(); i++) {
            if(s1[i] != s2[i]) diff++;
            if(diff > 1) return false;
        }

        return diff == 1 ? true : false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        unordered_map<string, vector<string>> graph;
        vector<string> temp = wordList;
        temp.push_back(beginWord);
        // temp.push_back(endWord);

        for(int i=0; i<temp.size(); i++) {
            for(int j=i+1; j<temp.size(); j++) {
                if(compare(temp[i], temp[j])) {
                    graph[temp[i]].push_back(temp[j]);
                    graph[temp[j]].push_back(temp[i]);
                }
            }
        }

        for(auto node : graph) {
            cout<<"Parent: "<<node.first<<endl;
            vector<string> nbrs = node.second;
            for(auto nbr : nbrs) {
                cout<<nbr<<" ";
            }
            cout<<endl;
        }

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> st;
        st.insert(beginWord);
        int level = 1;

        while(!q.empty()) {
            int size = q.size();
            

            while(size--) {
                string front = q.front();
                q.pop();
                
                
                if(front == endWord) {
                    return level;
                }

                for(string nbr : graph[front]) {
                    if(st.find(nbr) == st.end()) {
                        q.push(nbr);
                        st.insert(nbr);
                    }   
                }
            }

            level++;
        }

        return 0;
    }
};
