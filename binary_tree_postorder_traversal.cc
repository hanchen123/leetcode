class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> st; 
        TreeNode *pre = NULL; 
        TreeNode *top = NULL; 
        vector<int> ret;
        while ((root != NULL) || !st.empty()) { 
            if (root != NULL) { 
                st.push(root); 
                root = root->left; 
            } 
            else { 
                top = st.top(); 
                if(top->right != NULL && top->right != pre) 
                    root = top->right; 
                else { 
                    ret.push_back(top->val); 
                    pre = top; 
                    st.pop(); 
                } 
            } 
        } 
        return ret;
    }
};