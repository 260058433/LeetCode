#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class RepeatedDNASequences {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
            return vector<string>();
        vector<string> result;
        unordered_map<int, int> appeared;
        int cur = 0;
        for (int i = 0; i < 9; ++i)
            cur = cur << 3 | s[i] & 7;
        for (int i = 9; i < s.size(); ++i) {
            cur = (cur << 3 | s[i] & 7) & 0x3FFFFFFF;
            if (appeared[cur]++ == 1)
                result.push_back(s.substr(i - 9, 10));
        }
        return result;
    }
};
