class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ret;
        while ((root != NULL) || !st.empty()) {
            if (root != NULL) {
                ret.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                root = root->right;
            }
        } 
        return ret;
    }
};