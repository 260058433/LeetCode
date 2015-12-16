#include "TreeNode.cpp"
#include <vector>

using std::vector;

class BinaryTreeLevelOrderTraversal {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        vector<TreeNode *> level;
        if (root)
            level.push_back(root);
        while (!level.empty()) {
            vector<TreeNode *> tmp;
            vector<int> line;
            for (int i = 0; i < level.size(); ++i) {
                line.push_back(level[i]->val);
                if (level[i]->left)
                    tmp.push_back(level[i]->left);
                if (level[i]->right)
                    tmp.push_back(level[i]->right);
            }
            result.push_back(line);
            level = tmp;
        }
        return result;
    }
};
