#include "ListNode.cpp"

class InsertionSortList {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode **p = &head;
        while (*p) {
            ListNode **q = &head;
            while (*q != *p) {
                if ((*p)->val <= (*q)->val) {
                    ListNode *next = (*p)->next;
                    (*p)->next = *q;
                    *q = *p;
                    *p = next;
                    break;
                } else {
                    q = &((*q)->next);
                }
            }
            if (*q == *p)
                p = &((*p)->next);
        }
        return head;
    }
};
