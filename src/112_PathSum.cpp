#include "TreeNode.cpp"
#include <queue>
#include <utility>

using std::queue;
using std::pair;
using std::make_pair;

class PathSum {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        queue<pair<TreeNode *, int>> path;
        if (root)
            path.push(make_pair(root, sum - root->val));
        while (!path.empty()) {
            int n = path.size();
            for (int i = 0; i < n; ++i) {
                pair<TreeNode *, int> p = path.front();
                path.pop();
                if (p.second == 0 && p.first->left == nullptr && p.first->right == nullptr)
                    return true;
                if (p.first->left)
                    path.push(make_pair(p.first->left, p.second - p.first->left->val));
                if (p.first->right)
                    path.push(make_pair(p.first->right, p.second - p.first->right->val));
            }
        }
        return false;
    }
};
