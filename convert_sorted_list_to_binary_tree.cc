class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        int len = this->getLen(head);
        return this->Excute(head, 0, len - 1);
    }
private:
    int getLen(ListNode *head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    TreeNode *Excute(ListNode *head, int left, int right) {
        if (left > right) 
            return NULL;
        int mid = (left + right)/ 2;
        ListNode *tmp = head;
        for (int i = left; i < mid; i++) 
            tmp = tmp->next;
        TreeNode *root = new TreeNode(tmp->val);
        root->left = Excute(head, left, mid - 1);
        root->right = Excute(tmp->next, mid + 1, right);
        return root;
    }
};