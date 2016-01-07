#include <vector>
#include <unordered_set>
#include <string>

using std::vector;
using std::unordered_set;
using std::string;

class WordBreakII {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        int n = s.size();
        vector<bool> canBreak(n + 1);
        canBreak[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j)
                if (canBreak[j] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()) {
                    canBreak[i + 1] = true;
                    break;
                }
        }
        if (!canBreak[n])
            return vector<string>();
        vector<string> result;
        string cur;
        int longest = 0;
        for (auto p = wordDict.begin(); p != wordDict.end(); ++p)
            if (longest < p->size())
                longest = p->size();
        dfs(result, cur, s, 0, wordDict, longest);
        return result;
    }

private:
    void dfs(vector<string> &result, string &cur, string &s, int begin, unordered_set<string> &wordDict, int longest) {
        if (begin == s.size()) {
            result.push_back(cur);
            result.back().pop_back();
            return;
        }
        for (int i = 1; i <= s.size() - begin && i <= longest; ++i) {
            if (wordDict.find(s.substr(begin, i)) != wordDict.end()) {
                string tmp(cur);
                tmp += s.substr(begin, i);
                tmp.push_back(' ');
                dfs(result, tmp, s, begin + i, wordDict, longest);
            }
        }
    }
};
