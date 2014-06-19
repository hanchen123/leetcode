class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (row == 0 || col == 0) 
            return false;
        int left = 0, right = row - 1, mid;
        while (left < right) {
            mid = (left + right) / 2 + 1;
            if (matrix[mid][0] == target) 
                return true;
            else if (matrix[mid][0] > target) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        int target_row = right;
        left = 0;
        right = col - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[target_row][mid] == target) 
                return true;
            else if (matrix[target_row][mid] > target) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return false;
    }
};