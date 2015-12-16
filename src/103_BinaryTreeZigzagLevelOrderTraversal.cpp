#include "TreeNode.cpp"
#include <vector>

using std::vector;

class BinaryTreeZigzagLevelOrderTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        vector<TreeNode *> level;
        if (root)
            level.push_back(root);
        while (!level.empty()) {
            vector<TreeNode *> tmp;
            vector<int> line;
            for (int i = level.size() - 1; i >= 0; --i) {
                line.push_back(level[i]->val);
                if (level[i]->left)
                    tmp.push_back(level[i]->left);
                if (level[i]->right)
                    tmp.push_back(level[i]->right);
            }
            result.push_back(line);
            if (tmp.empty())
                break;
            level.clear();
            line.clear();
            for (int i = tmp.size() - 1; i >= 0; --i) {
                line.push_back(tmp[i]->val);
                if (tmp[i]->right)
                    level.push_back(tmp[i]->right);
                if (tmp[i]->left)
                    level.push_back(tmp[i]->left);
            }
            result.push_back(line);
        }
        return result;
    }
};
