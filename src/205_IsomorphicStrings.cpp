#include <string>
#include <vector>

using std::string;
using std::vector;

class IsomorphicStrings {
public:
    bool isIsomorphic(string s, string t) {
        vector<char> stot(128), ttos(128);
        for (int i = 0; i < s.size(); ++i) {
            if (stot[s[i]] == t[i]) {
                continue;
            } if (stot[s[i]] == 0 && ttos[t[i]] == 0) {
                stot[s[i]] = t[i];
                ttos[t[i]] = s[i];
            } else {
                return false;
            }
        }
        return true;
    }
};
