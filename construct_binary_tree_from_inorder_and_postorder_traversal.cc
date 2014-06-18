class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0 || inorder.size() == 0) 
            return NULL;
        return this->Excute(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
   TreeNode *Excute(vector<int> &postorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl > pr) 
            return NULL;
        TreeNode *root = new TreeNode(postorder[pr]);
        int mid = il;
        while (inorder[mid] != postorder[pr]) {
            mid++;
        }
        int len = mid - il;
        root->left = Excute(postorder, pl, pl + len - 1, inorder, il, mid - 1);
        root->right = Excute(postorder, pl + len, pr - 1, inorder, mid + 1, ir);
        return root;
    }
};