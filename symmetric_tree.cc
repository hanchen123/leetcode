class Solution {
public:

    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return this->isSymmetric_judge(root->left, root->right);
    }
private:
    bool isSymmetric_judge(TreeNode *lchild, TreeNode *rchild) {
        if (lchild == NULL && rchild == NULL)
            return true;
        if (lchild == NULL || rchild == NULL)
            return false;
        if (lchild->val != rchild->val) 
            return false;
        return isSymmetric_judge(lchild->left, rchild->right) && isSymmetric_judge(lchild->right, rchild->left);
    }
};