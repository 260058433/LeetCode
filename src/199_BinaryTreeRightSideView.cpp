#include "TreeNode.cpp"
#include <vector>
#include <queue>

using std::vector;
using std::queue;

class BinaryTreeRightSideView {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> path;
        if (root)
            path.push(root);
        while (!path.empty()) {
            int n = path.size();
            TreeNode *p;
            for (int i = 0; i < n; ++i) {
                p = path.front();
                path.pop();
                if (p->left)
                    path.push(p->left);
                if (p->right)
                    path.push(p->right);
            }
            result.push_back(p->val);
        }
        return result;
    }
};
