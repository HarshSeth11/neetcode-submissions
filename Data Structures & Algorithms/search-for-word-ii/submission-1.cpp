class TriesNode{
public:
    char val;
    TriesNode* children[26];
    bool isTerminal;

    TriesNode(char val) {
        this->val = val;
        for(int i=0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

class Solution {
public:
    TriesNode* head;
    vector<string> ans;
    Solution() {
        head = new TriesNode('0');
    }

    void insert(string& word) {
        TriesNode* temp = head;

        for(int i=0; i<word.size(); i++) {
            if(!temp->children[word[i]-'a']) temp->children[word[i]-'a'] = new TriesNode(word[i]);
            temp = temp->children[word[i]-'a'];

            if(i == word.size()-1) {
                temp->isTerminal = true;
            }
        }
    }

    void search(vector<vector<char>>& board, int i, int j, string& st, TriesNode* temp, vector<vector<bool>>& vis) {
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0) return;
        if(temp->isTerminal) {
            ans.push_back(st);
            temp->isTerminal = false;
        }

        vis[i][j] = true;

        if(i-1 >= 0 && temp->children[board[i-1][j]-'a'] && !vis[i-1][j]) {
            st += board[i-1][j];
            search(board, i-1, j, st, temp->children[board[i-1][j]-'a'], vis);
            st.pop_back();
        }
        if(j-1 >= 0 && temp->children[board[i][j-1]-'a'] && !vis[i][j-1]) {
            st += board[i][j-1];
            search(board, i, j-1, st, temp->children[board[i][j-1]-'a'], vis);
            st.pop_back();
        }
        if(j+1 < board[0].size() && temp->children[board[i][j+1]-'a'] && !vis[i][j+1]) {
            st += board[i][j+1];
            search(board, i, j+1, st, temp->children[board[i][j+1]-'a'], vis);
            st.pop_back();
        }
        if(i+1 < board.size() && temp->children[board[i+1][j]-'a'] && !vis[i+1][j]) {
            st += board[i+1][j];
            search(board, i+1, j, st, temp->children[board[i+1][j]-'a'], vis);
            st.pop_back();
        }

        vis[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<words.size(); i++) {
            insert(words[i]);
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        TriesNode* temp = head;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(temp->children[board[i][j]-'a']) {
                    string st;
                    st.push_back(board[i][j]);
                    search(board, i, j, st, temp->children[board[i][j]-'a'], vis);
                }
            }
        }

        return ans;
    }
};
