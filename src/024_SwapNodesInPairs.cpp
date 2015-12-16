#include "ListNode.cpp"

class SwapNodesInPairs {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **p = &head;
        while (*p && (*p)->next) {
            ListNode *q = *p;
            *p = q->next;
            q->next = (*p)->next;
            (*p)->next = q;
            p = &(q->next);
        }
        return head;
    }
};
