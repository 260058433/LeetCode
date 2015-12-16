#include <vector>

using std::vector;

class PascalsTriangle {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; ++i) {
            result[i].resize(i + 1);
            result[i][0] = 1;
            result[i][i] = 1;
            for (int j = 0; j < i - 1; ++j) {
                result[i][j + 1] = result[i - 1][j] + result[i - 1][j + 1];
            }
        }
        return result;
    }
};
