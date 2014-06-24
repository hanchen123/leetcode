class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int left = 0, right = n - 1, cur = 1;
        vector<vector<int> > ret;
        vector<int> tmp;
        for (int i = 0; i < n; i++) 
            tmp.push_back(0);
        for (int i = 0; i < n; i++) 
            ret.push_back(tmp);
        while (left <= right) {
            if (left == right) {
                ret[left][left] = cur;
                break;
            }
            for (int i = left; i < right; i++) {
                ret[left][i] = cur;
                ret[i][right] = cur + (right - left);
                ret[n - 1 - left][n - 1 - i] = cur + 2 * (right - left);
                ret[n - 1 - i][left] = cur + 3 * (right - left);
                cur++;
            }
            cur += (3 * (right - left));
            left++;
            right--;
        }
        return ret;        
    }
};