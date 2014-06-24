class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int row = matrix.size();
        if (row == 0) 
            return ret;
        int col = matrix[0].size();
        int ux = 0, uy = 0, dx = row - 1, dy = col - 1;
        while (ux < dx && uy < dy) {
            for (int i = uy; i < dy; i++) 
                ret.push_back(matrix[ux][i]);
            for (int i = ux; i < dx; i++) 
                ret.push_back(matrix[i][dy]);
            for (int i = dy; i > uy; i--) 
                ret.push_back(matrix[dx][i]);
            for (int i = dx; i > ux; i--) 
                ret.push_back(matrix[i][uy]);
            ux++, uy++;
            dx--, dy--;
        }
        if (ux == dx) {
            for (int i = uy; i <= dy; i++) 
                ret.push_back(matrix[ux][i]);
        } 
        else if (uy == dy) {
            for (int i = ux; i <= dx; i++) 
                ret.push_back(matrix[i][uy]);
        }
        return ret;        
    }
};