class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        TreeLinkNode *p = root;
        TreeLinkNode *cur = NULL;
        TreeLinkNode *nxt = NULL;
        for(; p != NULL; p = p->next) {
            if (p->left) {
                if (cur)
                    cur->next = p->left;
                cur = p->left;
                if (nxt == NULL)
                    nxt = cur;
            }
            if (p->right) {
                if (cur)
                    cur->next = p->right;
                cur = p->right;
                if (nxt == NULL)
                    nxt = cur;
            }
        }
        connect(nxt);        
    }
};