#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::string;

class ScrambleString {
public:
    bool isScramble(string s1, string s2) {
        /*
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        vector<int> map1(128), map2(128);
        int count1 = 0, count2 = 0;
        int n = s1.size();
        for (int i = 1; i < n; ++i) {
            if (map1[s1[i - 1]] == 0)
                ++count1;
            ++map1[s1[i - 1]];
            --map1[s2[n - i]];
            if (map1[s2[n - i]] == 0)
                --count1;
            if (count1 == 0 && isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)))
                return true;
            if (map2[s1[i - 1]] == 0)
                ++count2;
            ++map2[s1[i - 1]];
            --map2[s2[i - 1]];
            if (map2[s2[i - 1]] == 0)
                --count2;
            if (count2 == 0 && isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
                return true;
        }
        return false;
        */

        if (s1 == s2)
            return true;
        if (s1.size() != s2.size())
            return false;
        vector<int> count(128);
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            ++count[s1[i]];
            --count[s2[i]];
        }
        for (int i = 0; i < 128; ++i)
            if (count[i])
                return false;
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i)))
                return true;
        }
        return false;
    }
};
