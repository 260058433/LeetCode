#include <string>

using std::string;

class LengthOfLastWord {
public:
    int lengthOfLastWord(string s) {
        /*
        int i = 0;
        int n = s.size();
        while (n > 0 && s[n - 1] == ' ') {
            s.pop_back();
            --n;
        }
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                i = j + 1;
            }
        }
        return n - i;
        */

        int len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                ++len;
            } else if (i < s.size() - 1 && s[i + 1] != ' ') {
                len = 0;
            }
        }
        return len;
    }
};
