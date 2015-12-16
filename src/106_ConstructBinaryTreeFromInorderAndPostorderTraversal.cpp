#include "TreeNode.cpp"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class ConstructBinaryTreeFromInorderAndPostorderTraversal {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size() || inorder.empty())
            return nullptr;
        int i = inorder.size() - 1, j = postorder.size() - 1;
        TreeNode *root = new TreeNode(postorder[j--]);
        TreeNode *cur = root;
        stack<TreeNode *> path;
        while (i >= 0 && j >= 0) {
            if (cur->val == inorder[i]) {
                --i;
                if (i >= 0 && !path.empty() && inorder[i] == path.top()->val) {
                    cur = path.top();
                    path.pop();
                } else {
                    cur->left = new TreeNode(postorder[j--]);
                    cur = cur->left;
                }
            } else {
                cur->right = new TreeNode(postorder[j--]);
                path.push(cur);
                cur = cur->right;
            }
        }
        return root;
    }
};
