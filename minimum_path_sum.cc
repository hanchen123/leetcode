class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        int col = grid[0].size();
        if (row == 0 || col == 0) 
            return 0;
        vector<vector<int> > dp;
        vector<int> tmp;
        for (int i = 0; i < col; i++) 
            tmp.push_back(0);
        for (int i = 0; i < row; i++) 
            dp.push_back(tmp);
        dp[0][0] = grid[0][0];
        for (int i = 1; i < col; i++) 
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < row; i++) 
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < row; i++) 
            for (int j = 1; j < col; j++) 
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j]) + grid[i][j];
        return dp[row - 1][col - 1];        
    }
};