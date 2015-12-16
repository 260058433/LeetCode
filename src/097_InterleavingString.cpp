#include <string>
#include <vector>

using std::string;
using std::vector;

class InterleavingString {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size())
            return false;
        vector<bool> dp(m + 1, true);
        for (int i = 1; i <= m; ++i)
            dp[i] = dp[i - 1] && s2[i - 1] == s3[i - 1];
        for (int i = 1; i <= n; ++i) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= m; ++j) {
                if (dp[j - 1] && s2[j - 1] == s3[i + j - 1] || dp[j] && s1[i - 1] == s3[i + j - 1])
                    dp[j] = true;
                else
                    dp[j] = false;
            }
        }
        return dp[m];
    }
};
