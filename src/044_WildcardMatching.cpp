#include <string>

using std::string;

class WildcardMatching {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int pi = -1, pj = -1;
        while (i < s.size()) {
            if (j < p.size()) {
                if (s[i] == p[j] || p[j] == '?') {
                    ++i;
                    ++j;
                    continue;
                } else if (p[j] == '*') {
                    while (j < p.size() && p[j] == '*')
                        ++j;
                    if (j == p.size())
                        return true;
                    pi = i;
                    pj = j;
                    continue;
                }
            }
            if (pj != -1) {
                i = ++pi;
                j = pj;
            } else {
                return false;
            }
        }
        while (j < p.size() && p[j] == '*')
            ++j;
        return j == p.size();
    }
};
