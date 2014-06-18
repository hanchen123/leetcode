class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return this->Excute(1, n);
    }
private:
    vector<TreeNode *> Excute(int l, int r) {    
        vector<TreeNode *> ret;
        if (l > r) {
            ret.push_back(NULL);
            return ret;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode *> lchild = Excute(l, i - 1);
            vector<TreeNode *> rchild = Excute(i + 1, r);
            for (int j = 0; j < lchild.size(); j++) {
                for (int k = 0; k < rchild.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = lchild[j];
                    root->right = rchild[k];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};