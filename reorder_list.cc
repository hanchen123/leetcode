class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL) 
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        if (fast == NULL)   return;
        ListNode *cur = fast;
        ListNode *nxt = fast->next;
        cur->next = NULL;
        while(nxt) {
            ListNode *tmp = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = tmp;
        }
        ListNode *first = head;
        ListNode *second = cur;
        while(second && first && first != second) {
            ListNode *tmp = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = tmp;
        } 
        return;
    }
};