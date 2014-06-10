class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *G = new ListNode(INT_MIN);
        ListNode *cur = head;
        while(cur != NULL) {
            ListNode *nxt = cur->next;
            ListNode *ins = this->findInsertPlace(G, cur);
            cur->next = ins->next;
            ins->next = cur;
            cur = nxt;
        }
        ListNode *tmp = G->next;
        delete G;
        return tmp;
    }
private: 
    ListNode *findInsertPlace(ListNode *head, ListNode *cur) {
        while(head->next != NULL && head->next->val <= cur->val) {
            head = head->next;
        }
        return head;
    }        
};