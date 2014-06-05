class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == NULL) 
            return true;
        int dep = 0;
        return this->isBalanced_judge(root, dep);
    }
private:
    bool isBalanced_judge(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int lheight, rheight;
        if (isBalanced_judge(root->left, lheight) && isBalanced_judge(root->right, rheight)) {
            if (lheight > rheight + 1 || rheight > lheight + 1)
                return false;
            if (lheight > rheight) 
                depth = lheight + 1;
            else 
                depth = rheight + 1;
            return true;
        }
        return false;
    }
};