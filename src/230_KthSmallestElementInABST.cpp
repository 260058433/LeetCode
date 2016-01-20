#include "TreeNode.cpp"
#include <stack>

using std::stack;

class KthSmallestElementInABST {
public:
    int kthSmallest(TreeNode *root, int k) {
        /*
        int n = countNodes(root->left);
        if (k <= n)
            return kthSmallest(root->left, k);
        else if (k > n + 1)
            return kthSmallest(root->right, k - n - 1);
        else
            return root->val;
        */

        stack<TreeNode *> path;
        while (!path.empty() || root) {
            while (root) {
                path.push(root);
                root = root->left;
            }
            root = path.top();
            path.pop();
            if (--k == 0)
                break;
            root = root->right;
        }
        return root->val;
    }

private:
    int countNodes(TreeNode *root) {
        if (root == nullptr)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
