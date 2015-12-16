#include "TreeNode.cpp"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class PathSumII {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> line;
        stack<TreeNode *> path;
        TreeNode *cur = root, *pre = nullptr;
        while (cur || !path.empty()) {
            while (cur) {
                line.push_back(cur->val);
                sum -= cur->val;
                path.push(cur);
                cur = cur->left;
            }
            cur = path.top();
            if (sum == 0 && cur->left == nullptr && cur->right == nullptr)
                result.push_back(line);
            if (cur->right == nullptr || cur->right == pre) {
                sum += line.back();
                line.pop_back();
                path.pop();
                pre = cur;
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
        return result;
    }
};
