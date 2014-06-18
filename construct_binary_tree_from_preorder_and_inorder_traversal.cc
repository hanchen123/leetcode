class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) 
            return NULL;
        return this->Excute(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
   TreeNode *Excute(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl > pr) 
            return NULL;
        TreeNode *root = new TreeNode(preorder[pl]);
        int mid = il;
        while (inorder[mid] != preorder[pl]) {
            mid++;
        }
        int len = mid - il;
        root->left = Excute(preorder, pl + 1, pl + len, inorder, il, mid - 1);
        root->right = Excute(preorder, pl + len + 1, pr, inorder, mid + 1, ir);
        return root;
    }
};