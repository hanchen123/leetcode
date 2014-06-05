class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) 
            return NULL;
        return this->Excute(num, 0, num.size() - 1);
    }
private:
    TreeNode *Excute(vector<int> &num, int left, int right) {
        if (left > right) 
            return NULL;
        int mid = (left + right)/2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = Excute(num, left, mid - 1);
        root->right = Excute(num, mid + 1, right);
        return root;
    }
};