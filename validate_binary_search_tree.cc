class Solution {
public:
       bool isValidBST(TreeNode *root) {  
            return this->isValidBST_judge(root, INT_MIN, INT_MAX);  
       }  
private:
       bool isValidBST_judge(TreeNode* node, int MIN, int MAX)   
       {  
            if(node == NULL)  
                  return true;  
            if(node->val > MIN && node->val < MAX && isValidBST_judge(node->left,MIN,node->val) && isValidBST_judge(node->right,node->val,MAX))  
                 return true;  
            else   
                 return false;  
       }         

};