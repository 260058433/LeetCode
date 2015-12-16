#include <vector>
#include <string>

using std::vector;
using std::string;

class TextJustification {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        int i = 0;
        while (i < words.size()) {
            int j = i + 1;
            int len = words[i].size();
            while (j < words.size() && len + words[j].size() < maxWidth) {
                len += words[j].size() + 1;
                ++j;
            }
            string line = words[i];
            for (int k = i + 1; k < j; ++k) {
                if (j == words.size())
                    line.push_back(' ');
                else
                    line += string(1 + (maxWidth - len) / (j - i - 1) + (k - i <= (maxWidth - len) % (j - i - 1)), ' ');
                line += words[k];
            }
            if (j == i + 1 || j == words.size())
                line += string(maxWidth - line.size(), ' ');
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
