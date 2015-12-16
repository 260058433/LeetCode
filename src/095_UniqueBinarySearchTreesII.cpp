#include "TreeNode.cpp"
#include <vector>

using std::vector;

class UniqueBinarySearchTreesII {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n <= 0)
            return vector<TreeNode *>();
        return generateTrees(1, n);
    }

private:
    vector<TreeNode *> generateTrees(int b, int n) {
        if (n == 0)
            return vector<TreeNode *>(1);
        vector<TreeNode *> result;
        for (int i = 0; i < n; ++i) {
            vector<TreeNode *> l, r;
            l = generateTrees(b, i);
            r = generateTrees(b + i + 1, n - i - 1);
            for (int j = 0; j < l.size(); ++j) {
                for (int k = 0; k < r.size(); ++k) {
                    TreeNode *p = new TreeNode(b + i);
                    p->left = l[j];
                    p->right = r[k];
                    result.push_back(p);
                }
            }
        }
        return result;
    }
};
