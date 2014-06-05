class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret;
        vector<int> pre;
        for (int i = 1; i <= numRows; i++) {
            vector<int> cur;
            if (pre.size() == 0)
                cur.push_back(1);
            else {
                cur.push_back(1);
                for (int j = 1; j < i - 1; j++)
                    cur.push_back(pre[j - 1] + pre[j]);
                cur.push_back(1);
            }
            ret.push_back(cur);
            pre = cur;
        }
        return ret;
    }
};