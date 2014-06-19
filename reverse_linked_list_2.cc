class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int step = n - m;   
        ListNode *G = new ListNode(INT_MIN);  
        G->next = head;   
        ListNode *pre = G;   
        while(m > 1) {   
            pre = pre->next;   
            m--;   
        }   
        ListNode *cur = pre->next, *post = cur->next;   
        if(step>=1) {   
            while(step > 0 && post!=NULL) {   
                ListNode *tmp = post->next;   
                post->next = cur;   
                cur = post;   
                post = tmp;   
                step--;   
            }   
            ListNode *tmp = pre->next;   
            pre->next = cur;   
            tmp->next = post;   
        }   
        ListNode *ret = G->next;   
        delete G;   
        return ret;             
    }
};