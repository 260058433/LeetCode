struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class CopyListWithRandomPointer {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr)
            return nullptr;
        RandomListNode *p = head;
        while (p) {
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while (p) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        RandomListNode *result = head->next;
        while (p) {
            RandomListNode *q = p->next;
            p->next = q->next;
            p = p->next;
            if (p)
                q->next = p->next;
        }
        return result;
    }
};
