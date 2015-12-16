#include "ListNode.cpp"

class RemoveDuplicatesFromSortedListII {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **p = &head;
        while (*p) {
            if ((*p)->next && (*p)->val == (*p)->next->val) {
                ListNode *q = (*p)->next;
                while (q && q->next && q->val == q->next->val)
                    q = q->next;
                *p = q->next;
            } else {
                p = &(*p)->next;
            }
        }
        return head;
    }
};
