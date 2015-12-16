#include "TreeNode.cpp"
#include <stack>
#include <vector>
#include <algorithm>

using std::stack;
using std::vector;
using std::swap;

class RecoverBinarySearchTree {
public:
    void recoverTree(TreeNode *root) {
        /*
        stack<TreeNode *> path;
        vector<TreeNode *> inorder;
        TreeNode *cur = root;
        while (cur || !path.empty()) {
            while (cur) {
                path.push(cur);
                cur = cur->left;
            }
            cur = path.top();
            path.pop();
            inorder.push_back(cur);
            cur = cur->right;
        }
        TreeNode *first, *second;
        for (int i = 0; i < inorder.size() - 1; ++i) {
            if (inorder[i]->val > inorder[i + 1]->val) {
                first = inorder[i];
                break;
            }
        }
        for (int i = inorder.size() - 1; i > 0; --i) {
            if (inorder[i]->val < inorder[i - 1]->val) {
                second = inorder[i];
                break;
            }
        }
        swap(first->val, second->val);
        */

        stack<TreeNode *> path;
        TreeNode *cur = root, *pre = nullptr;
        TreeNode *first = nullptr, *second = nullptr;
        while (cur || !path.empty()) {
            while (cur) {
                path.push(cur);
                cur = cur->left;
            }
            cur = path.top();
            path.pop();
            if (pre && pre->val > cur->val) {
                if (first == nullptr) {
                    first = pre;
                    second = cur;
                } else {
                    second = cur;
                }
            }
            pre = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
