class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();  
        if(row == 0) 
            return 0;  
        vector<int> ret(triangle[row-1].size()); 
        for(int i = 0; i < triangle[row-1].size(); i++) 
            ret[i] = triangle[row-1][i];  
        for(int i = row - 2; i >= 0; i--) {  
            int col = triangle[i].size();  
            for(int j = 0; j < col; j++)   
                ret[j] = min(ret[j], ret[j+1]) + triangle[i][j];  
        }  
        return ret[0]; 
    }
};