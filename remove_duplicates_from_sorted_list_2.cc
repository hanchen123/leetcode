class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) 
            return head;  
        ListNode *G = new ListNode(INT_MIN);  
        G->next = head;  
        ListNode *slow = G;
        ListNode *fast = head;  
        while(fast != NULL) {  
            bool flag = false;  
            while(fast->next != NULL && fast->val == fast->next->val) {  
                flag = true;  
                ListNode *tmp = fast;  
                fast = fast->next;  
            }  
            if(flag) {  
                ListNode *tmp = fast;  
                fast = fast->next;  
                continue;  
            }  
            slow->next = fast;  
            slow = slow->next;  
            fast = fast->next;  
        }  
        slow->next = NULL;  
        ListNode *tmp = G->next;  
        delete G;  
        return tmp;        
    }
};