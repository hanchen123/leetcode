class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;  
        vector<int> tmp;  
        int target = sum;
        if(root!=NULL)  
            this->Excute(root, target, 0, tmp, ret);  
        return ret;  
    } 
private:
    void Excute(TreeNode *node, int target, int sum, vector<int>& tmp, vector<vector<int> >& ret) {   
        tmp.push_back(node->val);  
        sum += node->val;  
        if(sum == target && node->left == NULL && node->right == NULL)    
            ret.push_back(tmp);        
        else {      
            if(node->left != NULL)  
                Excute(node->left, target, sum, tmp, ret);        
            if(node->right != NULL)  
                Excute(node->right, target, sum, tmp, ret);  
        }  
        tmp.pop_back();  
        sum -= node->val;  
    }
};