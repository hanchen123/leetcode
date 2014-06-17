class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int tmp = INT_MIN;
        int ret = this->Excute(root, tmp);
        return max(ret, tmp);        
    }
private:
    int Excute(TreeNode *node, int &tmp) {  
        if(node == NULL) return 0;  
        int left = Excute(node->left, tmp);  
        int right = Excute(node->right, tmp);  
        int mid = node->val;  
        if(left > 0)  
            mid += left;  
        if(right > 0)  
            mid += right;  
        tmp = max(tmp, mid);  
        return max(node->val, max(node->val+left, node->val+right));  
    }     
};