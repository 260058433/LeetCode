#include <string>
#include <vector>

using std::string;
using std::vector;

class MinimumWindowSubstring {
public:
    string minWindow(string s, string t) {
        vector<int> key(128), appear(128);
        for (int i = 0; i < t.size(); ++i)
            ++key[t[i]];
        int i = 0, j = 0;
        int b = 0, len = 0;
        int count = 0;
        while (j < s.size()) {
            if (key[s[j]] != 0) {
                ++appear[s[j]];
                if (appear[s[j]] <= key[s[j]])
                    ++count;
                if (count == t.size()) {
                    while (i < j) {
                        if (appear[s[i]] != 0) {
                            if (appear[s[i]] > key[s[i]])
                                --appear[s[i]];
                            else if (appear[s[i]] == key[s[i]])
                                break;
                        }
                        ++i;
                    }
                    if (j - i + 1 < len || len == 0) {
                        b = i;
                        len = j - i + 1;
                    }
                }
            }
            ++j;
        }
        return s.substr(b, len);
    }
};
