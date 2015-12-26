#include "TreeNode.cpp"
#include <algorithm>
#include <utility>

using std::max;
using std::pair;
using std::make_pair;

class BinaryTreeMaximumPathSum {
public:
    int maxPathSum(TreeNode *root) {
        return maxSum(root).first;
    }

private:
    pair<int, int> maxSum(TreeNode *root) {
        if (root == nullptr)
            return make_pair(0, 0);
        pair<int, int> left = maxSum(root->left);
        pair<int, int> right = maxSum(root->right);
        pair<int, int> result;
        result.first = root->val;
        if (left.second > 0)
            result.first += left.second;
        if (right.second > 0)
            result.first += right.second;
        if (root->left)
            result.first = max(left.first, result.first);
        if (root->right)
            result.first = max(right.first, result.first);
        result.second = max(0, max(left.second, right.second)) + root->val;
        return result;
    }
};
