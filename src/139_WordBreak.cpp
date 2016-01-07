#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class WordBreak {
public:
    bool wordBreak(string s, unordered_set<string> &wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
