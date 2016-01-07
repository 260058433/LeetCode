#include "ListNode.cpp"

class IntersectionOfTwoLinkedLists {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode *p1 = headA, *p2 = headB;
        while (p1) {
            ++n1;
            p1 = p1->next;
        }
        while (p2) {
            ++n2;
            p2 = p2->next;
        }
        int i = 0;
        p1 = headA;
        p2 = headB;
        while (i < n1 - n2) {
            ++i;
            p1 = p1->next;
        }
        while (i < n2 - n1) {
            ++i;
            p2 = p2->next;
        }
        while (p1) {
            if (p1 == p2)
                break;
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
