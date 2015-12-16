#include "TreeNode.cpp"
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class BalancedBinaryTree {
public:
    bool isBalanced(TreeNode *root) {
        /*
        if (root == nullptr)
            return true;
        unordered_map<TreeNode *, int> heights;
        heights[nullptr] = 0;
        getHeight(root, heights);
        vector<TreeNode *> level{root};
        while (!level.empty()) {
            vector<TreeNode *> tmp;
            for (int i = 0; i < level.size(); ++i) {
                int diff = heights[level[i]->left] - heights[level[i]->right];
                if (diff < -1 || diff > 1)
                    return false;
                if (level[i]->left)
                    tmp.push_back(level[i]->left);
                if (level[i]->right)
                    tmp.push_back(level[i]->right);
            }
            level = tmp;
        }
        return true;
        */

        return balancedHeight(root) != -1;
    }

private:
    void getHeight(TreeNode *root, unordered_map<TreeNode *, int> &heights) {
        if (root->left == nullptr && root->right == nullptr) {
            heights[root] = 1;
            return;
        }
        if (root->left)
            getHeight(root->left, heights);
        if (root->right)
            getHeight(root->right, heights);
        int l = heights[root->left], r = heights[root->right];
        heights[root] = (l < r ? r : l) + 1;
    }

    int balancedHeight(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int l = balancedHeight(root->left);
        int r = balancedHeight(root->right);
        if (l == -1 || r == -1 || l - r < -1 || l - r > 1)
            return -1;
        else
            return (l < r ? r : l) + 1;
    }
};
