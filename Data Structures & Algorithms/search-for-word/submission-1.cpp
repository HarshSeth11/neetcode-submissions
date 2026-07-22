class Solution {
public:
    bool helper(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if(i >= board.size() || j >= board[0].size()) return false;
        else if(index >= word.size()) return true;

        visited[i][j] = true;

        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;

        if(i-1 >= 0 && word[index] == board[i-1][j] && !visited[i-1][j]) {
            up = helper(board, word, i-1, j, index+1, visited);
            if(up) return true;
        }  
        if(i+1 < board.size() && word[index] == board[i+1][j] && !visited[i+1][j]) {
            down = helper(board, word, i+1, j, index+1, visited);
            if(down) return true;
        }
        if(j-1 >= 0 && word[index] == board[i][j-1] && !visited[i][j-1]) {
            left = helper(board, word, i, j-1, index+1, visited);
            if(left) return true;
        }
        if(j+1 < board[0].size() && word[index] == board[i][j+1] && !visited[i][j+1]) {
            right = helper(board, word, i, j+1, index+1, visited);
            if(right) return true;
        }

        visited[i][j] = false;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool ans = false;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    ans = helper(board, word, i, j, 1, visited);
                    visited[i][j] = false;
                }
                if(ans) return true;
            }
        }

        return false;
    }
};
