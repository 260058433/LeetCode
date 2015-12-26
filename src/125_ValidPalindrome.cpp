#include <string>

using std::string;

class ValidPalindrome {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isAlphanumeric(s[i]))
                ++i;
            while (i < j && !isAlphanumeric(s[j]))
                --j;
            if (!charEqual(s[i], s[j]))
                return false;
            ++i;
            --j;
        }
        return true;
    }

private:
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    bool charEqual(char c1, char c2) {
        return c1 - c2 == 0 || c1 - c2 == 'a' - 'A' || c1 - c2 == 'A' - 'a';
    }
};
