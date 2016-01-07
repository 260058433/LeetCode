#include "TreeNode.cpp"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class BinaryTreePostorderTraversal {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> path;
        TreeNode *cur = root, *pre = nullptr;
        while (!path.empty() || cur) {
            while (cur) {
                path.push(cur);
                cur = cur->left;
            }
            cur = path.top();
            if (cur->right == nullptr || cur->right == pre) {
                path.pop();
                result.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
        return result;
    }
};
