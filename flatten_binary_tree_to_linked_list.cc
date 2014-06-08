class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) 
            return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        flatten(left);
        flatten(right);
        root->left = NULL;
        root->right = left;
        TreeNode *cur = root;
        while (cur->right != NULL) {
            cur = cur->right;
        }
        cur->right = right;
        return;
    }
};