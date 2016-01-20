#include "ListNode.cpp"

class ReverseLinkedList {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *p = head, *q = nullptr;
        while (p) {
            ListNode *next = p->next;
            p->next = q;
            q = p;
            p = next;
        }
        return q;
    }
};
