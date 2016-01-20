#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

class WordPattern {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> ptos(26);
        unordered_map<string, int> stop;
        int i = 0, j = 0;
        for (; i < pattern.size() && j < str.size(); ++i) {
            int k = j;
            while (k < str.size() && str[k] != ' ')
                ++k;
            string s = str.substr(j, k - j);
            j = k + 1;
            if (ptos[pattern[i] - 'a'].empty() && stop.find(s) == stop.end()) {
                ptos[pattern[i] - 'a'] = s;
                stop[s] = pattern[i];
            } else {
                if (ptos[pattern[i] - 'a'] != s || stop[s] != pattern[i])
                    return false;
            }
        }
        return i >= pattern.size() && j >= str.size();
    }
};
