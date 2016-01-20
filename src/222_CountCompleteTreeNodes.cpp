#include "TreeNode.cpp"

class CountCompleteTreeNodes {
public:
    int countNodes(TreeNode *root) {
        int h1 = 0, h2 = 0;
        TreeNode *p = root;
        while (p) {
            ++h1;
            p = p->left;
        }
        p = root;
        while (p) {
            ++h2;
            p = p->right;
        }
        if (h1 == h2)
            return (1 << h1) - 1;
        else
            return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
