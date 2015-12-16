#include <string>
#include <stack>

using std::string;
using std::stack;

class SimplifyPath {
public:
    string simplifyPath(string path) {
        if (path.empty() || path[0] != '/')
            return string();
        stack<string> paths;
        int i = 1;
        while (i < path.size()) {
            int j = i;
            while (j < path.size() && path[j] != '/')
                ++j;
            string s = path.substr(i, j - i);
            if (s == "..") {
                if (!paths.empty())
                    paths.pop();
            } else if (!s.empty() && s != ".") {
                paths.push(s);
            }
            i = j + 1;
        }
        string result;
        while (!paths.empty()) {
            result = "/" + paths.top() + result;
            paths.pop();
        }
        if (result.empty())
            result.push_back('/');
        return result;
    }
};
