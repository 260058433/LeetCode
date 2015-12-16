#include "TreeNode.cpp"
#include <vector>

using std::vector;

class SymmetricTree {
public:
    bool isSymmetric(TreeNode *root) {
        /*
        if (root == nullptr)
            return true;
        return isSymmetric(root->right, root->left);
        */

        if (root == nullptr)
            return true;
        vector<TreeNode *> line;
        line.push_back(root->left);
        line.push_back(root->right);
        while (!line.empty()) {
            vector<TreeNode *> tmp;
            for (int i = 0; i < line.size(); i += 2) {
                if (line[i] == nullptr ^ line[i + 1] == nullptr)
                    return false;
                if (line[i] && line[i + 1]) {
                    if (line[i]->val != line[i + 1]->val)
                        return false;
                    tmp.push_back(line[i]->left);
                    tmp.push_back(line[i + 1]->right);
                    tmp.push_back(line[i]->right);
                    tmp.push_back(line[i + 1]->left);
                }
            }
            line = tmp;
        }
        return true;
    }

private:
    bool isSymmetric(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        } else if (t1 == nullptr || t2 == nullptr || t1->val != t2->val) {
            return false;
        } else {
            return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
        }
    }
};
