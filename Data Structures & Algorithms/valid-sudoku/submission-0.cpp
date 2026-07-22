class Solution {
public:
    bool checkRows(vector<vector<char>>& board, int row, int col) {
        int val = board[row][col];
        for(int i=0; i<9; i++) {
            if(i != row && board[i][col] == val) return false;
        }

        return true;
    }

    bool checkCols(vector<vector<char>>& board, int row, int col) {
        int val = board[row][col];
        for(int i=0; i<9; i++) {
            if(i != col && board[row][i] == val) return false;
        }

        return true;
    }

    bool checkBox(vector<vector<char>>& board, int row, int col) {
        int val = board[row][col];

        int st_row = (row/3)*3;
        int en_row = st_row + 3;
        int st_col = (col/3)*3;
        int en_col = st_col+3;

        for(int i=st_row; i<en_row; i++) {
            for(int j=st_col; j<en_col; j++) {
                if(i != row && j != col && board[i][j] == val) return false;
            }
        }

        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                if(!checkRows(board, i, j) || !checkCols(board, i, j) || !checkBox(board, i, j)) return false;
            }
        }

        return true;
    }
};
