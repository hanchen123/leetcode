class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
        bool flag = true;
        TreeNode *cur = NULL;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            curdep = dep.front();
            dep.pop();
            if (curdep > mindep) {
                mindep = curdep;
                if (!flag)
                    reverse(tmp.begin(), tmp.end());
                flag = !flag;
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
        if (tmp.size()) {
            if(!flag)
                reverse(tmp.begin(), tmp.end());
            ret.push_back(tmp);            
        }
        return ret;        
    }
};