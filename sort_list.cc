class Solution {
public:
    ListNode *sortList(ListNode *head) {  
        if(head == NULL) return NULL;  
        int len = 0;  
        ListNode* p = head;  
        while(p!= NULL)  
        {  
            len++;  
            p = p->next;  
        }  
        ListNode* newHead = this->Sort(&head, len);  
        return newHead;  
    }  
private:
    ListNode* Sort(ListNode** head, int length) {  
         if (length == 1) {  
              ListNode* tmp = *head;            
              *head = (*head)->next;  
              tmp->next = NULL; 
              return tmp;  
         }  
         ListNode* leftHead = Sort(head, length / 2); 
         ListNode* rightHead = Sort(head, length - length / 2);  
         ListNode* newHead = Merge(leftHead, rightHead);  
         return newHead;  
    }  
    ListNode* Merge(ListNode* first, ListNode* second) {  
        ListNode* head = new ListNode(INT_MIN);  
        ListNode* cur = head;  
        while(first!=NULL || second!=NULL) {  
            int fn = first == NULL? INT_MAX:first->val;  
            int sn = second == NULL? INT_MAX:second->val;  
            if(fn<=sn) {  
                cur->next = first;  
                first = first->next;  
            }  
            else {  
                cur->next = second;  
                second = second->next;  
            }  
            cur = cur->next;  
        }  
        cur = head->next;  
        delete head;  
        return cur; 
    }
};