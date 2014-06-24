class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> st;
        vector<int> ret;
        while ((root != NULL) || !st.empty()) {
            if (root != NULL) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                ret.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }
        return ret;
    }
};