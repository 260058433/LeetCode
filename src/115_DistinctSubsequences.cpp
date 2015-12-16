#include <string>
#include <vector>

using std::string;
using std::vector;

class DistinctSubsequences {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size())
            return 0;
        vector<int> dp(s.size() + 1, 1);
        for (int i = 1; i <= t.size(); ++i) {
            int pre = dp[i - 1];
            dp[i - 1] = 0;
            for (int j = i; j <= s.size(); ++j) {
                if (t[i - 1] == s[j - 1]) {
                    int tmp = dp[j];
                    dp[j] = dp[j - 1] + pre;
                    pre = tmp;
                } else {
                    pre = dp[j];
                    dp[j] = dp[j - 1];
                }
            }
        }
        return dp[s.size()];
    }
};
