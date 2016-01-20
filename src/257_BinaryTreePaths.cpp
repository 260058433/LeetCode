#include "TreeNode.cpp"
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

class BinaryTreePaths {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        dfs(result, string(), root);
        return result;
    }

private:
    void dfs(vector<string> &result, string cur, TreeNode *node) {
        if (node == nullptr)
            return;
        cur = cur + to_string(node->val) + "->";
        if (node->left == nullptr && node->right == nullptr)
            result.push_back(string(cur.begin(), cur.end() - 2));
        dfs(result, cur, node->left);
        dfs(result, cur, node->right);
    }
};
