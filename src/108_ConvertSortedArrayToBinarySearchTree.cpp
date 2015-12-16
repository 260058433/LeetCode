#include "TreeNode.cpp"
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::pair;
using std::make_pair;

class ConvertSortedArrayToBinarySearchTree {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        /*
        return toBST(nums, 0, nums.size());
        */

        if (nums.empty())
            return nullptr;
        TreeNode *root = new TreeNode(0);
        queue<TreeNode *> path;
        queue<pair<int, int>> range;
        path.push(root);
        range.push(make_pair(0, nums.size()));
        while (!path.empty()) {
            TreeNode *p = path.front();
            path.pop();
            int b = range.front().first, e = range.front().second;
            range.pop();
            int m = b + (e - b) / 2;
            p->val = nums[m];
            if (b < m) {
                TreeNode *l = new TreeNode(0);
                p->left = l;
                path.push(l);
                range.push(make_pair(b, m));
            }
            if (m + 1 < e) {
                TreeNode *r = new TreeNode(0);
                p->right = r;
                path.push(r);
                range.push(make_pair(m + 1, e));
            }
        }
        return root;
    }

private:
    TreeNode *toBST(vector<int> &nums, int b, int e) {
        if (b == e)
            return nullptr;
        int m = b + (e - b + 1) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = toBST(nums, b, m);
        root->right = toBST(nums, m + 1, e);
        return root;
    }
};
