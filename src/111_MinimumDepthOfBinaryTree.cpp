#include "TreeNode.cpp"
#include <queue>

using std::queue;

class MinimumDepthOfBinaryTree {
public:
    int minDepth(TreeNode *root) {
        int height = 0;
        queue<TreeNode *> level;
        if (root)
            level.push(root);
        while (!level.empty()) {
            ++height;
            int n = level.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *p = level.front();
                level.pop();
                if (p->left == nullptr && p->right == nullptr)
                    return height;
                if (p->left)
                    level.push(p->left);
                if (p->right)
                    level.push(p->right);
            }
        }
        return height;
    }
};
