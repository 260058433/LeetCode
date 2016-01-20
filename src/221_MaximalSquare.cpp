#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

class MaximalSquare {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();       
        vector<int> lengths(n + 1);
        int maxLength = 0;
        for (int i = 0; i < m; ++i) {
            int pre = 0;
            for (int j = 0; j < n; ++j) {
                int tmp = lengths[j + 1];
                if (matrix[i][j] == '0')
                    lengths[j + 1] = 0;
                else
                    lengths[j + 1] = min(pre, min(lengths[j], lengths[j + 1])) + 1;
                pre = tmp;
                maxLength = max(maxLength, lengths[j + 1]);
            }
        }
        return maxLength * maxLength;
    }
};
