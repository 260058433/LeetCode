#include <string>
#include <vector>

using std::string;
using std::vector;

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return string();
        string result;
        int i = 0;
        while (i < strs[0].size()) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].size() || strs[j][i] != c)
                    return result;
            }
            result.push_back(c);
            ++i;
        }
        return result;
    }
};
