class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int st_x = 0;
        int st_y = 0;
        int end_x = matrix.size()-1;
        int end_y = matrix[0].size()-1;

        vector<int> ans;

        while(st_x <= end_x || st_y <= end_y) {
            for(int i=st_y; st_x <= end_x && i<=end_y; i++) {
                ans.push_back(matrix[st_x][i]);
            }
            st_x++;
            for(int i=st_x; st_y <= end_y && i<=end_x; i++) {
                ans.push_back(matrix[i][end_y]);
            }
            end_y--;
            for(int i=end_y; st_x <= end_x && i>=st_y; i--) {
                ans.push_back(matrix[end_x][i]);
            }
            end_x--;
            for(int i=end_x; st_y <= end_y && i>=st_x; i--) {
                ans.push_back(matrix[i][st_y]);
            }
            st_y++;
        }

        return ans;
    }
};

// [[1,2,3,4]
// ,[5,6,7,8]
// ,[9,10,11,12]]
