#include "ListNode.cpp"

class RemoveLinkedListElements {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode **p = &head;
        while (*p) {
            if ((*p)->val == val) {
                *p = (*p)->next;
            } else {
                p = &((*p)->next);
            }
        }
        return head;
    }
};
