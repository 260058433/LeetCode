#include "ListNode.cpp"

class ReverseNodesInKGroup {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1)
            return head;
        ListNode **p = &head;
        while (*p != nullptr) {
            ListNode *q = *p;
            int i = 1;
            while (q->next != nullptr && i != k) {
                q = q->next;
                ++i;
            }
            if (i != k)
                break;
            ListNode *t = *p, *pre = q->next;
            *p = q;
            p = &(t->next);
            while (pre != q) {
                ListNode *next = t->next;
                t->next = pre;
                pre = t;
                t = next;
            }
        }
        return head;
    }
};
