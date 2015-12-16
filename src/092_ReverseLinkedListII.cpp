#include "ListNode.cpp"

class ReverseLinkedListII {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode **p = &head;
        for (int i = 1; i < m; ++i)
            p = &((*p)->next);
        ListNode *pre = *p, *cur = (*p)->next;
        for (int i = m; i < n; ++i) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        (*p)->next = cur;
        *p = pre;
        return head;
    }
};
