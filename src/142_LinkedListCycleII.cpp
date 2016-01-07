#include "ListNode.cpp"

class LinkedListCycleII {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
