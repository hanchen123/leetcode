class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (row == 0 || col == 0) 
            return;
        bool col_flag = false, row_flag = false;
        for (int i = 0; i < col; i++) 
            if (matrix[0][i] == 0) 
                col_flag = true;
        for (int i = 0; i < row; i++) 
            if (matrix[i][0] == 0) 
                row_flag = true;
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < row; i++)  
            for(int j = 1; j < col; j++)  
                if(matrix[i][0] == 0 || matrix[0][j] == 0)  
                    matrix[i][j] = 0; 
        if (col_flag) {
            for (int i = 0; i < col; i++) 
                matrix[0][i] = 0;
        }
        if (row_flag) {
            for (int i = 0; i < row; i++) 
                matrix[i][0] = 0;
        }
        return;        
    }
};