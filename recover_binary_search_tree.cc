class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *pre = NULL, *first = NULL, *second = NULL;
        this->Excute(pre, root, first, second);
        if (first != NULL && second != NULL) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
private:
    void Excute(TreeNode * &pre, TreeNode *cur, TreeNode *&first, TreeNode *&second) {
        if (cur == NULL) 
            return;
        Excute(pre, cur->left, first, second);
        if (pre != NULL && pre->val > cur->val) {
            if (first == NULL) {
                first = pre;
            }
            second = cur;
        }
        pre = cur;
        Excute(pre, cur->right, first, second);
    }
};