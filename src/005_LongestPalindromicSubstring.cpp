#include <string>
#include <vector>

using std::string;
using std::vector;

class LongestPalindromicSubstring {
public:
    string longestPalindrome(string s) {
        /*
        if (s.empty())
            return s;
        string result = s.substr(0, 1);
        vector<int> palindromes;
        for (string::size_type i = 0; i < s.size(); ++i) {
            vector<int> tmp;
            for (int j = 0; j < palindromes.size(); ++j) {
                if (palindromes[j] > 0 && s[palindromes[j] - 1] == s[i]) {
                    tmp.push_back(palindromes[j] - 1);
                    if (i - palindromes[j] + 2 > result.size())
                        result = s.substr(palindromes[j]- 1, i - palindromes[j] + 2);
                }
            }
            if (i > 0 && s[i - 1] == s[i]) {
                tmp.push_back(i - 1);
                if (result.size() < 2)
                    result = s.substr(i - 1, 2);
            }
            tmp.push_back(i);
            palindromes = tmp;
        }
        return result;
        */

        /*
        if (s.empty())
            return s;
        int begin = 0, end = 0;
        for (int i = 0; i < s.size(); ) {
            if (s.size() - i <= (end - begin + 1) / 2)
                break;
            int j = i, k = i;
            while (k < s.size() - 1 && s[k] == s[k + 1])
                ++k;
            i = k + 1;
            while (j > 0 && k < s.size() - 1 && s[j - 1] == s[k + 1]) {
                --j;
                ++k;
            }
            if (k - j > end - begin) {
                begin = j;
                end = k;
            }
        }
        return s.substr(begin, end - begin + 1);
        */

        string str(2 * s.size() + 1, '#');
        for (int i = 0; i < s.size(); ++i)
            str[2 * i + 1] = s[i];
        vector<int> longest(str.size(), 0);
        int id = 0;
        int result = 0;
        for (int i = 1; i < str.size(); ++i) {
            int j = 0;
            if (2 * id - i >= 0)
                j = longest[2 * id - i];
            if (i + j > id + longest[id])
                j = id + longest[id] - i;
            while (i - j - 1 >= 0 && i + j + 1 < str.size() && str[i - j - 1] == str[i + j + 1])
                ++j;
            longest[i] = j;
            if (longest[result] < longest[i])
                result = i;
            if (i + longest[i] > id + longest[id])
                id = i;
        }
        return s.substr((result - longest[result]) / 2, longest[result]);
    }
};
