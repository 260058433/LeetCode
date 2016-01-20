#include "TreeNode.cpp"
#include <stack>

using std::stack;

class InvertBinaryTree {
public:
    TreeNode *invertTree(TreeNode *root) {
        /*
        if (root == nullptr)
            return nullptr;
        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
        */

        stack<TreeNode *> path;
        if (root)
            path.push(root);
        while (!path.empty()) {
            TreeNode *p = path.top();
            path.pop();
            TreeNode *tmp = p->left;
            p->left = p->right;
            p->right = tmp;
            if (p->right)
                path.push(p->right);
            if (p->left)
                path.push(p->left);
        }
        return root;
    }
};
