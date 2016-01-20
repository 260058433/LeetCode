#include <string>
#include <vector>

using std::string;
using std::vector;

class ShortestPalindrome {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return string();
        vector<int> next(s.size());
        initNext(next, s);
        string t(s.rbegin(), s.rend());
        int i = 0, j = 0, n = s.size();
        while (i < n) {
            if (j == -1) {
                ++i;
                j = 0;
            }
            else if (t[i] == s[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        return t.substr(0, n - j) + s;
    }

private:
    void initNext(vector<int> &next, string &s) {
        next[0] = -1;
        for (int i = 1; i < s.size(); ++i) {
            int j = next[i - 1];
            while (j != -1 && s[i - 1] != s[j])
                j = next[j];
            next[i] = j + 1;
        }
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[next[i]])
                next[i] = next[next[i]];
        }
    }
};
