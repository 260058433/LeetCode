#include <string>
#include <vector>

using std::string;
using std::vector;

class PalindromePartitioning {
public:
    vector<vector<string>> partition(string s) {
        /*
        vector<vector<vector<string>>> dp(s.size() + 1);
        dp[0].push_back(vector<string>());
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (isPalindrome(s, j, i)) {
                    for (int k = 0; k < dp[j].size(); ++k) {
                        dp[i + 1].push_back(dp[j][k]);
                        dp[i + 1].back().push_back(s.substr(j, i - j + 1));
                    }
                }
            }
        }
        return dp[s.size()];
        */

        vector<vector<string>> result;
        vector<string> cur;
        dfs(result, cur, s, 0);
        return result;
    }

private:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void dfs(vector<vector<string>> &result, vector<string> &cur, string &s, int begin) {
        if (begin == s.size())
            result.push_back(cur);
        for (int i = begin; i < s.size();) {
            if (isPalindrome(s, begin, i++)) {
                cur.push_back(s.substr(begin, i - begin));
                dfs(result, cur, s, i);
                cur.pop_back();
            }
        }
    }
};
