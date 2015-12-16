#include "TreeNode.cpp"
#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

class BinaryTreeLevelOrderTraversalII {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        vector<TreeNode *> path;
        if (root)
            path.push_back(root);
        while (!path.empty()) {
            vector<TreeNode *> tmp;
            vector<int> line;
            for (int i = 0; i < path.size(); ++i) {
                line.push_back(path[i]->val);
                if (path[i]->left)
                    tmp.push_back(path[i]->left);
                if (path[i]->right)
                    tmp.push_back(path[i]->right);
            }
            result.push_back(line);
            path = tmp;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
