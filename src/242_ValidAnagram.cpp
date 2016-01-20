#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::sort;

class ValidAnagram {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> counts(26);
        for (int i = 0; i < s.size(); ++i) {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
            if (counts[i])
                return false;
        return true;

        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        */
    }
};
