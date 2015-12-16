#include "TreeNode.cpp"

class MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int l = maxDepth(root->left), r = maxDepth(root->right);
        return (l < r ? r : l) + 1;
    }
};
