#include "ListNode.cpp"

class PartitionList {
public:
    ListNode *partition(ListNode *head, int x) {
        /*
        ListNode **p = &head;
        while (*p && (*p)->val < x) {
            p = &((*p)->next);
        }
        ListNode **q = p;
        while (*q) {
            while (*q && (*q)->val >= x)
                q = &((*q)->next);
            if (*q) {
                ListNode *t = *q;
                *q = t->next;
                t->next = *p;
                *p = t;
                p = &(t->next);
            }
        }
        return head;
        */

        ListNode first(0), second(0);
        ListNode *p = &first, *q = &second;
        while (head) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = nullptr;
        p->next = second.next;
        return first.next;
    }
};
