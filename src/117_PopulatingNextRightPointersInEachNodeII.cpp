struct TreeLinkNode {
    int val;
    TreeLinkNode  *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class PopulatingNextRightPointersInEachNodeII {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root;
        while (p) {
            TreeLinkNode *q = p;
            p = nullptr;
            TreeLinkNode *pre = nullptr;
            while (q) {
                if (q->left) {
                    if (p == nullptr)
                        p = q->left;
                    else
                        pre->next = q->left;
                    pre = q->left;
                }
                if (q->right) {
                    if (p == nullptr)
                        p = q->right;
                    else
                        pre->next = q->right;
                    pre = q->right;
                }
                q = q->next;
            }
        }
    }
};
