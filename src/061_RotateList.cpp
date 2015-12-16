#include "ListNode.cpp"

class RotateList {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (k <= 0 || head == nullptr)
            return head;
        int n = 1;
        ListNode *p = head;
        while (p->next) {
            ++n;
            p = p->next;
        }
        p->next = head;
        k = k % n;
        if (k != 0) {
            for (int i = 0; i < n - k; ++i)
                p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
