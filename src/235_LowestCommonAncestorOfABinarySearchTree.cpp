#include "TreeNode.cpp"
#include <algorithm>

using std::swap;

class LowestCommonAncestorOfABinarySearchTree {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (q->val < p->val)
            swap(p, q);
        while (true) {
            if (p->val <= root->val && q->val >= root->val)
                break;
            else if (q->val < root->val)
                root = root->left;
            else if (p->val > root->val)
                root = root->right;
        }
        return root;
    }
};
