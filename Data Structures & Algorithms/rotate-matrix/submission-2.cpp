class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverseColumns(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n/2; i++) {
            for(int j=0; j<n; j++) {
                swap(matrix[j][i], matrix[j][n-i-1]);
            }
        }        
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseColumns(matrix);
    }
};
