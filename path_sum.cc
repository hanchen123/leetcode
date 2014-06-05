class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {  
            return this->hasPathSum_judge(root, 0, sum);      
    }  
private:
    bool hasPathSum_judge(TreeNode *root, int sum, int target) {  
        if(root == NULL) 
            return false;  
        sum += root->val;  
        if(root->left == NULL && root->right == NULL) {  
            if(sum == target)  
                return true;  
            else  
                return false;  
        }  
        return hasPathSum_judge(root->left, sum, target) || hasPathSum_judge(root->right, sum, target);      
    }  
};