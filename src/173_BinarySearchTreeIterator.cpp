#include "TreeNode.cpp"
#include <stack>

using std::stack;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    bool hasNext() {
        return cur || !path.empty();
    }
    
    int next() {
        while (cur) {
            path.push(cur);
            cur = cur->left;
        }
        cur = path.top();
        path.pop();
        int result = cur->val;
        cur = cur->right;
        return result;
    }

private:
    TreeNode *cur;
    stack<TreeNode *> path;
};
