class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL)
            return 0;
        int ret = 0;
        this->Excute(0, ret, root);
        return ret;
    }
private:
    void Excute(int cur, int& ret, TreeNode *root) {
        cur = 10 *cur + root->val;
        if (root->left == NULL && root->right == NULL) {
            ret += cur;
            return;
        }
        if (root->left != NULL)
            Excute(cur, ret, root->left);
        if (root->right != NULL)
            Excute(cur, ret, root->right);
    }
};