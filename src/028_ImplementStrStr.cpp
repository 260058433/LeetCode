#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using namespace std;

class ImplementStrStr {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        vector<int> next(needle.size());
        initNext(next, needle);
        int i = 0, j = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
                if (j == -1) {
                    ++i;
                    j = 0;
                }
            }
        }
        if (j == needle.size())
            return i - j;
        else
            return -1;
    }

private:
    void initNext(vector<int> &next, string &needle) {
        next[0] = -1;
        for (int i = 1; i < needle.size(); ++i) {
            int j = next[i - 1];
            while (j != -1 && needle[j] != needle[i - 1])
                j = next[j];
            next[i] = j + 1;
        }
        for (int i = 1; i < needle.size(); ++i) {
            if (needle[i] == needle[next[i]])
                next[i] = next[next[i]];
        }
    }
};
