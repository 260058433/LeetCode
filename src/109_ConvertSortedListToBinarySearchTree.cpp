#include "TreeNode.cpp"
#include "ListNode.cpp"

class ConvertSortedListToBinarySearchTree {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        //return toBST(head, nullptr);
        
        int n = 0;
        ListNode *p = head;
        while (p) {
            ++n;
            p = p->next;
        }
        return generate(&head, n);
    }

private:
    TreeNode *toBST(ListNode *head, ListNode *tail) {
        if (head == tail)
            return nullptr;
        ListNode *p = head, *q = head;
        while (p != tail && p->next != tail) {
            p = p->next->next;
            q = q->next;
        }
        TreeNode *t = new TreeNode(q->val);
        t->left = toBST(head, q);
        t->right = toBST(q->next, tail);
        return t;
    }

    TreeNode *generate(ListNode **head, int n) {
        if (n == 0)
            return nullptr;
        TreeNode *l = generate(head, n / 2);
        TreeNode *root = new TreeNode((*head)->val);
        *head = (*head)->next;
        TreeNode *r = generate(head, n - n / 2 - 1);
        root->left = l;
        root->right = r;
        return root;
    }
};
