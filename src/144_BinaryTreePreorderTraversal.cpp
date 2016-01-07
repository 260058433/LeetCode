#include "TreeNode.cpp"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class BinaryTreePreorderTraversal {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> path;
        if (root)
            path.push(root);
        while (!path.empty()) {
            TreeNode *p = path.top();
            path.pop();
            result.push_back(p->val);
            if (p->right)
                path.push(p->right);
            if (p->left)
                path.push(p->left);
        }
        return result;
    }
};
