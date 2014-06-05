class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode *> que;
        queue<int> dep;
        que.push(root);
        dep.push(1);
        TreeNode *cur;
        int curdep = 0;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            curdep = dep.front();
            dep.pop();
            if (cur->left == NULL && cur->right == NULL) {
                return curdep;
            }
            if (cur->left) {
                que.push(cur->left);
                dep.push(curdep + 1);
            }
            if (cur->right) {
                que.push(cur->right);
                dep.push(curdep + 1);
            }
        }
        return curdep;
    }
};