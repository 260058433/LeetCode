#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
//        unordered_map<char, int> ht;
        vector<int> ht(256, -1);
        int b = 0;
        int length = 0;
        for (string::size_type i = 0; i < s.size(); ++i) {
            /*
            if (ht.find(s[i]) != ht.end()) {
                b = ht[s[i]] >= b ? ht[s[i]] + 1 : b;
            }
            */
            b = ht[s[i]] >= b ? ht[s[i]] + 1 : b;
            ht[s[i]] = i;
            if (i - b + 1 > length)
                length = i - b + 1;
        }
        return length;
    }
};
