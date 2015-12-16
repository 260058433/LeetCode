#include <string>
#include <vector>

using std::string;
using std::vector;

class LongestValidParentheses {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int result = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(') {
                dp[i] = 0;
            } else {
                int j = i - 1 - dp[i - 1];
                if (j < 0 || s[j] != '(') {
                    dp[i] = 0;
                } else {
                    dp[i] = i - j + 1;
                    if (j > 0)
                        dp[i] += dp[j - 1];
                    if (result < dp[i])
                        result = dp[i];
                }
            }
        }
        return result;
    }
};
