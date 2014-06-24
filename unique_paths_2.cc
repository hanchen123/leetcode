class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if (row == 0 || col == 0) 
            return 0;
        vector<vector<int> > ret;
        vector<int> tmp;
        for (int i = 0; i < col; i++) 
            tmp.push_back(0);
        for (int i = 0; i < row; i++) 
            ret.push_back(tmp);
        ret[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for (int i = 1; i < row; i++) 
            ret[i][0] = (obstacleGrid[i][0] == 1) ? 0 : ret[i - 1][0];
        for (int i = 1; i < col; i++) 
            ret[0][i] = (obstacleGrid[0][i] == 1) ? 0 : ret[0][i - 1];
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) 
                    ret[i][j] = 0;
                else 
                    ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
            }
        }
        return ret[row - 1][col - 1];        
    }
};