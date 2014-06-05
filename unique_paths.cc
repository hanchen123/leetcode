class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int> > ret;
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            tmp.push_back(0);
        }
        for (int i = 0; i < m; i++) {
            ret.push_back(tmp);
        }
        for (int i = 0; i < m; i++) {
            ret[i][0]=1;
        }
        for (int i = 0; i < n; i++) {
            ret[0][i]=1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ret[i][j] = ret[i - 1][j] + ret[i][j - 1];
            }
        }
        return ret[m-1][n-1];
    }
};