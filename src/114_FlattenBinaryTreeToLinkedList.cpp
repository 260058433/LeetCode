#include "TreeNode.cpp"
#include <stack>

using std::stack;

class FlattenBinaryTreeToLinkedList {
public:
    void flatten(TreeNode *root) {
        /*
        stack<TreeNode *> path;
        TreeNode dump(0);
        TreeNode *pre = &dump;
        if (root)
            path.push(root);
        while (!path.empty()) {
            TreeNode *p = path.top();
            path.pop();
            pre->left = nullptr;
            pre->right = p;
            pre = p;
            if (p->right)
                path.push(p->right);
            if (p->left)
                path.push(p->left);
        }
        */

        while (root) {
            if (root->left) {
                TreeNode *p = root->left;
                while (p->right)
                    p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};
