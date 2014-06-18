class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ret;
        if (root == NULL) 
            return ret;
        vector<int> tmp;
        stack<vector<int> > st;
        queue<TreeNode *> que;
        queue<int> dep;
        que.push(root);
        dep.push(1);
        int curdep; 
        int mindep = 1;
        TreeNode *cur = NULL;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            curdep = dep.front();
            dep.pop();
            if (curdep > mindep) {
                mindep = curdep;
                st.push(tmp);
                tmp.clear();
            }
            tmp.push_back(cur->val);
            if (cur->left) {
                que.push(cur->left);
                dep.push(curdep + 1);
            }
            if (cur->right) {
                que.push(cur->right);
                dep.push(curdep + 1);
            }
        }
        if (tmp.size()) 
            st.push(tmp);
        while(!st.empty()) {
            ret.push_back(st.top());  
            st.pop();
        }
        return ret;        
    }
};