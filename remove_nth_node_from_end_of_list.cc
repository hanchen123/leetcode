class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *slow, *fast;  
        slow = head; 
        fast = head;  
        int i = 0;  
        while(i < n && fast != NULL) {  
            fast = fast->next;  
            i++;  
        }  
        if(i == n && fast == NULL) {  
            head = head->next;  
            delete slow;  
            return head;  
        }  
        while(fast->next != NULL) {  
            slow = slow->next;  
            fast = fast->next;  
        }  
        ListNode *temp = slow->next;  
        slow->next = temp->next;  
        delete temp;      
        return head;        
    }
};