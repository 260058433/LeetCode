#include <string>
#include <vector>
#include <queue>

using std::string;
using std::vector;
using std::queue;

class PalindromePartitioningII {
public:
    int minCur(string s) {
        if (s.empty())
            return 0;
        int n = s.size();
        vector<int> counts(n + 1, n);
        counts[0] = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; i - j > 0 && i + j < n && s[i - j - 1] == s[i + j]; ++j) {
                if (counts[i - j - 1] + 1 < counts[i + j + 1])
                    counts[i + j + 1] = counts[i - j - 1] + 1;
            }
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j) {
                if (counts[i - j] + 1 < counts[i + j + 1])
                    counts[i + j + 1] = counts[i - j] + 1;
            }
        }
        return counts[n];
    }
};

