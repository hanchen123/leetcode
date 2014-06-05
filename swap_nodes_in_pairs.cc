class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {  
            return head;  
        }  
        ListNode* second = head->next->next;  
        ListNode* first = head->next;  
        head->next->next = head;  
        head->next = swapPairs(second);  
        return first;          
    }
};