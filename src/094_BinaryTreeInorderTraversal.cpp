#include "TreeNode.cpp"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class BinaryTreeInorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        /*
        vector<int> result;
        stack<TreeNode *> path;
        if (root)
            path.push(root);
        TreeNode *pre = root;
        while (!path.empty()) {
            TreeNode *p = path.top();
            if (p->right == pre) {
                path.pop();
                pre = p;
            } else if (p->left == nullptr || p->left == pre) {
                result.push_back(p->val);
                path.pop();
                pre = p;
                if (p->right != nullptr) {
                    path.push(p);
                    path.push(p->right);
                }
            } else {
                path.push(p->left);
            }
        }
        return result;
        */

        vector<int> result;
        stack<TreeNode *> path;
        TreeNode *cur = root;
        while (cur || !path.empty()) {
            while (cur) {
                path.push(cur);
                cur = cur->left;
            }
            cur = path.top();
            path.pop();
            result.push_back(cur->val);
            cur = cur->right;
        }
        return result;
    }
};
