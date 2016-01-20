#include "ListNode.cpp"

class PalindromeLinkedList {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *cur = slow, *pre = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode *p = head, *q = pre;
        while (q) {
            if (p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        cur = pre;
        pre = nullptr;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return true;
    }
};
