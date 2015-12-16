struct TreeLinkNode {
    int val;
    TreeLinkNode  *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class PopulatingNextRightPointersInEachNode {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;
        TreeLinkNode *p = root;
        while (p->left) {
            TreeLinkNode *q = p;
            p = p->left;
            while (q) {
                q->left->next = q->right;
                if (q->next)
                    q->right->next = q->next->left;
                q = q->next;
            }
        }
    }
};
