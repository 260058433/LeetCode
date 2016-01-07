#include "ListNode.cpp"

class ReorderList {
public:
    void reorderList(ListNode *head) {
        ListNode fake(0);
        fake.next = head;
        ListNode *fast = &fake, *slow = &fake;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p = slow->next, *q = nullptr;
        slow->next = nullptr;
        while (p) {
            ListNode *next = p->next;
            p->next = q;
            q = p;
            p = next;
        }
        p = head;
        while (q) {
            ListNode *next = q->next;
            q->next = p->next;
            p->next = q;
            q = next;
            p = p->next->next;
        }
    }
};
