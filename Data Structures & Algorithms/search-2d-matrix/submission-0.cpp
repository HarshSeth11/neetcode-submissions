class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int st = 0;
        int en = m*n-1;

        while(st <= en) {
            int mid = (st+en)/2;

            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) st = mid+1;
            else en = mid-1;
        }

        return false;
    }
};
