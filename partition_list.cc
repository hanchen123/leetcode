class Solution {
public:
    ListNode *partition(ListNode *head, int x) {  
        ListNode *G = new ListNode(INT_MIN);  
        G->next = head;  
        ListNode *p = G;
        ListNode *cur;  
        while(p != NULL && p->val < x) {  
            cur = p;  
            p = p->next;  
        }  
        if(p != NULL) {      
            ListNode *pre = cur;  
            while(p != NULL) {  
                if(p->val < x) {  
                    ListNode *tmp = pre->next;  
                    cur->next = p->next;  
                    pre->next = p;  
                    pre = p;  
                    p->next = tmp;  
                    p = cur;  
                }  
                cur = p;  
                p = p->next;        
            }  
        }  
        ListNode *ret = G->next;  
        delete G;  
        return ret;      
    }  
};