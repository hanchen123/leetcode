class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || k == 0) 
            return head;  
        int len = 1;  
        ListNode *cur = head;  
        while(cur->next!=NULL) {
            cur = cur->next;  
            len++;      
        }  
        k = len-k%len;  
        cur->next = head;  
        while(k) {  
            cur = cur->next;  
            k--;  
        }  
        head = cur->next;  
        cur->next = NULL;  
        return head;         
    }
};