#include <vector>
#include <string>

using std::vector;
using std::string;

class GenerateParentheses {
public:
    vector<string> generateParentheses(int n) {
        if (n < 0)
            return vector<string>();
        vector<vector<string>> dp(n + 1);
        dp[0].push_back(string());
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (int k = 0; k < dp[j].size(); ++k) {
                    string first = "(" + dp[j][k] + ")";
                    for (int l = 0; l < dp[i - j - 1].size(); ++l) {
                        dp[i].push_back(first + dp[i - j -1][l]);
                    }
                }
            }
        }
        return dp[n];
    }
};
