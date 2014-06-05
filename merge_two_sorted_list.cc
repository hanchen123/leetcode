class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;  
        if(l2 == NULL) return l1;  
        ListNode *head = new ListNode(INT_MIN);  
        ListNode *ret = head;  
        while(l1 != NULL && l2!=NULL) {  
            if(l1->val < l2->val) {  
                ret->next = l1;  
                l1= l1->next;  
            }  
            else {  
                ret->next = l2;  
                l2 = l2->next;  
            }  
            ret = ret->next;  
        }  
        ret->next = (l1 == NULL) ? l2:l1;
        ret = head->next;  
        delete head;  
        return ret;         
    }
};