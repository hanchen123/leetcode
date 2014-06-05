class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *G = new ListNode(INT_MIN);  
        ListNode *cur = G;  
        ListNode *first = l1, *second = l2;  
        int carry = 0; 
        if (first == NULL && second == NULL) return NULL;
        while (first != NULL || second != NULL) {  
            int a = first == NULL? 0:first->val;  
            int b = second == NULL? 0:second->val; 
            int sum = a + b + carry;
            ListNode *node = new ListNode(sum%10);  
            carry = sum/10;  
            cur->next = node;  
            cur = cur->next;  
            first = first==NULL? NULL:first->next;  
            second = second==NULL? NULL:second->next;  
        }            
        if(carry)  
            cur->next = new ListNode(1);  
        cur = G->next;  
        delete G;  
        return cur;          
    }
};