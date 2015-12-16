#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::max;
using std::min;

class MaximalRectangle {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        /*
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int result = 0;
        vector<int> height(matrix[0].size() + 1);
        for (int i = 0; i < matrix.size(); ++i) {
            stack<int> index;
            for (int j = 0; j <= matrix[0].size(); ++j) {
                if (j < matrix[0].size()) {
                    if (matrix[i][j] == '0')
                        height[j] = 0;
                    else
                        ++height[j];
                }
                while (!index.empty() && height[j] < height[index.top()]) {
                    int h = height[index.top()];
                    index.pop();
                    int tmp = h * (index.empty() ? j : j - index.top() - 1);
                    if (result < tmp)
                        result = tmp;
                }
                index.push(j);
            }
        }
        return result;
        */

        if (matrix.empty() || matrix[0].empty())
            return 0;
        int result = 0;
        int n = matrix[0].size();
        vector<int> height(n), left(n), right(n, n);
        for (int i = 0; i < matrix.size(); ++i) {
            int curL = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                    left[j] = 0;
                    curL = j + 1;
                } else {
                    ++height[j];
                    left[j] = max(left[j], curL);
                }
            }
            int curR = n;
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    curR = j;
                    right[j] = n;
                } else {
                    right[j] = min(right[j], curR);
                }
            } 
            for (int j = 0; j < n; ++j) {
                int tmp = (right[j] - left[j]) * height[j];
                if (result < tmp)
                    result = tmp;
            }
        }
        return result;
    }
};
