#include "TreeNode.cpp"
#include <queue>
#include <utility>

using std::queue;
using std::pair;
using std::make_pair;

class SumRootToLeafNumbers {
public:
    int sumNumbers(TreeNode *root) {
        int result = 0;
        queue<pair<TreeNode *, int>> path;
        if (root)
            path.push(make_pair(root, root->val));
        while (!path.empty()) {
            int n = path.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *p = path.front().first;
                int cur = path.front().second;
                path.pop();
                if (p->left == nullptr && p->right == nullptr) {
                    result += cur;
                } else {
                    if (p->left)
                        path.push(make_pair(p->left, cur * 10 + p->left->val));
                    if (p->right)
                        path.push(make_pair(p->right, cur * 10 + p->right->val));
                }
            }
        }
        return result;
    }
};
