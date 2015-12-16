#include "ListNode.cpp"

class MergeTwoSortedLists {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode preHead(0);
        ListNode *p = &preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 != nullptr)
            p->next = l1;
        else
            p->next = l2;
        return preHead.next;
    }
};
