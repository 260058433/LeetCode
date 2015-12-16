#include <string>
#include <vector>

using std::string;
using std::vector;

class RegularExpressionMatching {
public:
    bool isMatch(string s, string p) {
        /*
        int m = s.size(), n = p.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == p[j] || p[j] == '.') {
                if (j == n - 1 || p[j + 1] != '*')
                    ++i;
                ++j;
            } else if (p[j] == '*') {
                do {
                    if (isMatch(s.substr(i, m - i), p.substr(j + 1, n - j - 1)))
                        return true;
                    ++i;
                } while (i <= m && (p[j - 1] == '.' || s[i - 1] == p[j - 1]));
                return false;
            } else {
                if (j < n - 1 && p[j + 1] == '*') {
                    j += 2;
                } else { 
                    return false;
                }
            }
        }
        if (j < n && p[j] == '*')
            ++j;
        while (j < n - 1 && p[j + 1] == '*') {
            j += 2;
        }
        return i == m && j == n;
        */

        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        dp[0][0] = true;
        for (int i = 2; i <= n; i += 2) {
            if (p[i - 1] == '*')
                dp[0][i] = true;
            else
                break;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (dp[i][j - 1] || dp[i][j - 2])
                        dp[i][j] = true;
                    if (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                        dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};
