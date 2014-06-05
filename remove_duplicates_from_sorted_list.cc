class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return NULL;  
        ListNode *slow = head;  
        ListNode *fast = head->next;  
        while(fast!=NULL) {  
            if(slow->val == fast->val) {  
                ListNode* temp = fast;  
            fast = fast->next;  
            slow->next = fast;  
            delete temp;  
            continue;  
            }  
            slow = slow->next;  
            fast = fast->next;  
        }  
        return head;        
    }
};