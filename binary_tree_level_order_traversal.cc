class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        if (root == NULL) 
            return ret;
        vector<int> tmp;
        queue<TreeNode *> que;
        queue<int> dep;
        que.push(root);
        dep.push(1);
        int curdep; 
        int mindep = 1;
        TreeNode *cur = NULL;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            curdep = dep.front();
            dep.pop();
            if (curdep > mindep) {
                mindep = curdep;
                ret.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(cur->val);
            if (cur->left) {
                que.push(cur->left);
                dep.push(curdep + 1);
            }
            if (cur->right) {
                que.push(cur->right);
                dep.push(curdep + 1);
            }
        }
        if (tmp.size()) 
            ret.push_back(tmp);
        return ret;
    }
};