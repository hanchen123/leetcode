class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return head;
        RandomListNode *cur = head;
        while(cur != NULL) {
            RandomListNode *tmp = new RandomListNode(cur->label);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        cur = head;
        while(cur != NULL) {
            RandomListNode *tmp = cur->next;
            if(cur->random != NULL)
                tmp->random = cur->random->next;
            cur = tmp->next;
        }
        cur = head;
        RandomListNode *ret = head->next;
        while(cur != NULL) {
            RandomListNode *tmp = cur->next;
            cur->next = tmp->next;
            if(tmp->next != NULL)
                tmp->next = tmp->next->next;
            cur = cur->next;
        }
        return ret;        
    }
};