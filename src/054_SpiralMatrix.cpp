#include <vector>

using std::vector;

class SpiralMatrix {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return vector<int>();
        vector<int> result;
        int i = 0, j = matrix.size() - 1, k = 0, l = matrix[0].size() - 1;
        while (i <= j && k <= l) {
            for (int a = k; a <= l; ++a)
                result.push_back(matrix[i][a]);
            ++i;
            for (int a = i; a <= j; ++a)
                result.push_back(matrix[a][l]);
            --l;
            if (i <= j) {
                for (int a = l; a >= k; --a)
                    result.push_back(matrix[j][a]);
                --j;
            }
            if (k <= l) {
                for (int a = j; a >= i; --a)
                    result.push_back(matrix[a][k]);
                ++k;
            }
        }
        return result;
    }
};
