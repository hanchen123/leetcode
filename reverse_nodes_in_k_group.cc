class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *G = new ListNode(INT_MIN);  
        G->next = head;            
        if(head == NULL || k == 1) 
            return head;  
        ListNode *pre = G, *cur = head, *post = head->next;  
        while(cur!=NULL) {  
            post = cur->next;  
            int i = 0;  
            while(i < k-1 && post != NULL) {  
                ListNode *tmp = post->next;  
                post->next = cur;  
                cur = post;  
                post = tmp;  
                i++;  
            }  
            if(i != k-1) {  
                int k = 0;  
                ListNode *tmp = post;  
                post = cur;  
                cur = tmp;  
                while(k < i) {  
                    tmp = post->next;  
                    post->next = cur;  
                    cur = post;  
                    post = tmp;  
                    k++;  
                }  
                break;  
            }  
            ListNode *tmp = pre->next;  
            pre->next = cur;  
            tmp->next = post;  
            pre = tmp;  
            cur = pre->next;  
        }  
        ListNode *ret = G->next;  
        delete G;  
        return ret;          
    }
};