#include "ListNode.cpp"

class RemoveNthNodeFromEndOfList {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p = head, **q = &head;
        while (p != nullptr && n != 0) {
            p = p->next;
            --n;
        }
        if (n != 0)
            return head;
        while (p != nullptr) {
            p = p->next;
            q = &((*q)->next);
        }
        *q = (*q)->next;
        return head;
    }
};
