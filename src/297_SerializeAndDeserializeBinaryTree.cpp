#include "TreeNode.cpp"
#include <queue>
#include <string>

using std::queue;
using std::string;
using std::to_string;
using std::stoi;

class Codec {
public:
    string serialize(TreeNode *root) {
        string result;
        queue<TreeNode *> path;
        path.push(root);
        while (!path.empty()) {
            TreeNode *p = path.front();
            path.pop();
            if (p == nullptr) {
                result.push_back('#');
            } else {
                result += to_string(p->val);
                path.push(p->left);
                path.push(p->right);
            }
            result.push_back(' ');
        }
        return result;
    }

    TreeNode *deserialize(string data) {
        if (data[0] == '#')
            return nullptr;
        int i = data.find(' ');
        TreeNode *root = new TreeNode(stoi(data.substr(0, i++)));
        queue<TreeNode *> path;
        path.push(root);
        while (i < data.size()) {
            TreeNode *p = path.front();
            path.pop();
            int j = data.find(' ', i);
            if (data[i] != '#') {
                p->left = new TreeNode(stoi(data.substr(i, j - i)));
                path.push(p->left);
            }
            i = ++j;
            j = data.find(' ', i);
            if (data[i] != '#') {
                p->right = new TreeNode(stoi(data.substr(i, j - i)));
                path.push(p->right);
            }
            i = ++j;
        }
        return root;
    }
};
