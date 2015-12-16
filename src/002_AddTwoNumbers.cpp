#include "ListNode.cpp"

class AddTwoNumbers {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        } else if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        int sum = 0;
        ListNode preHead(0);
        ListNode *pre = &preHead;
        while (l1 != nullptr || l2 != nullptr || sum) {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode *t = new ListNode(sum % 10);
            pre->next = t;
            pre = t;
            sum /= 10;
        }
        return preHead.next;
    }
};
