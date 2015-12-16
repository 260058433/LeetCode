#include <string>
#include <vector>

using std::string;
using std::vector;

class EditDistance {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            dp[i] = i;
        for (int i = 1; i <= m; ++i) {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int tmp = pre;
                pre = dp[j];
                dp[j] = (dp[j] < dp[j - 1] ? dp[j] : dp[j - 1]) + 1;
                if (word1[i - 1] != word2[j - 1])
                    ++tmp;
                if (tmp < dp[j])
                    dp[j] = tmp;
            }
        }
        return dp[n];
    }
};
