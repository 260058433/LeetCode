#include "TreeNode.cpp"

class LowestCommonAncestorOfABinaryTree {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        if (left && !right)
            return left;
        else if (!left && right)
            return right;
        else
            return nullptr;
    }
};
