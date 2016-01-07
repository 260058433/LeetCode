#include <string>
#include <algorithm>

using std::string;
using std::reverse;

class ReverseWordsInAString {
public:
    void reverseWords(string &s) {
        if (s.empty())
            return;
        int n = s.size();
        int i = 0, j = 0;;
        while (i < n) {
            while (i < n && s[i] == ' ')
                ++i;
            j = i;
            while (j < n && s[j] != ' ')
                ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        i = 0, j = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                ++i;
            if (i < n) {
                while (i < n && s[i] != ' ')
                    s[j++] = s[i++];
                s[j++] = ' ';
            }
        }
        if (j == 0)
            s = string();
        else
            s = s.substr(0, j - 1);
        reverse(s.begin(), s.end());
    }
};
