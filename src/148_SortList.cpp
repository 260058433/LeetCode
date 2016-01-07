#include "ListNode.cpp"

class SortList {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *half = slow->next;
        slow->next = nullptr;
        ListNode *p = sortList(head), *q = sortList(half);
        ListNode newHead(0);
        ListNode *cur = &newHead;
        while (p && q) {
            if (p->val < q->val) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        cur->next = p ? p : q;
        return newHead.next;
    }
};
