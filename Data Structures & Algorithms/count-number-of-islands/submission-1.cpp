class Solution {
public:
int dir[4][4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
        

        grid[i][j] = '0';

        for(int k=0; k<4; k++) {
            dfs(grid, i+dir[k][0], j+dir[k][1]);
        }
    }

    // void print(vector<vector<char>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     for(int i=0; i<n; i++) {
    //         for(int j=0; j<m; j++) {
    //             cout<<grid[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j);
                    // print(grid);
                    // cout<<"<----------------------------->"<<endl;
                }
            }
        }

        return ans;
    }
};
