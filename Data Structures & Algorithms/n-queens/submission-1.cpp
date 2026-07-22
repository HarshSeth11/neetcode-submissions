class Solution {
public:
    vector<vector<string>> ans;

    bool isSafe(int x, int y, vector<string>& temp) {
        int i = x;
        int j = y;

        // horizontally
        while(i >= 0) {
            if(temp[i][j] == 'Q') return false;
            i--;
        }

        // diagonally
        i=x;
        j=y;

        while(j >= 0 && i >= 0) {
            if(temp[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i=x;
        j=y;

        while(j < temp[0].size() && i >= 0) {
            if(temp[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void debug(vector<string>& temp) {
        for(string s : temp) {
            cout<<s<<endl;
        }
        cout<<"****************"<<endl;
    }

    void helper(int n, vector<string>& temp, int start) {
        if(start >= n) {
            ans.push_back(temp);
            return;
        }


        for(int j=0; j<n; j++) {
            if(isSafe(start, j, temp)) {
                temp[start][j] = 'Q';
                // debug(temp);
                helper(n, temp, start+1);
                temp[start][j] = '.';
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        
        helper(n, temp, 0);

        return ans;
    }
};
