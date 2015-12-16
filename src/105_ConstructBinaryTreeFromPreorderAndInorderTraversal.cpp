#include "TreeNode.cpp"
#include <vector>

using std::vector;

class ConstructBinaryTreeFromPreorderAndInorderTraversal {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size())
            return nullptr;
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode *build(vector<int> &preorder, int pb, int pe, vector<int> &inorder, int ib, int ie) {
        if (pb == pe)
            return nullptr;
        int i = ib;
        while (inorder[i] != preorder[pb])
            ++i;
        TreeNode *root = new TreeNode(preorder[pb]);
        root->left = build(preorder, pb + 1, pb + 1 + (i - ib), inorder, ib, i);
        root->right = build(preorder, pb + 1 + (i - ib), pe, inorder, i + 1, ie);
        return root;
    }
};
