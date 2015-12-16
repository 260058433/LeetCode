#include "TreeNode.cpp"
#include <stack>
#include <functional>

using std::stack;
using std::less_equal;
using std::greater_equal;

class ValidateBinarySearchTree {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;
        TreeNode *p = root->left;
        while (p) {
            if (root->val <= p->val)
                return false;
            p = p->right;
        }
        p = root->right;
        while (p) {
            if (p->val <= root->val)
                return false;
            p = p->left;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
