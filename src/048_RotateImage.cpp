#include <vector>

using std::vector;

class RotateImage {
public:
    void rotate(vector<vector<int>> &matrix) {
        int i = 0, j = matrix.size() - 1;
        while (i < j) {
            for (int k = i; k < j; ++k) {
                int tmp = matrix[i][k];
                matrix[i][k] = matrix[j - k + i][i];
                matrix[j - k + i][i] = matrix[j][j - k + i];
                matrix[j][j - k + i] = matrix[k][j];
                matrix[k][j] = tmp;
            }
            ++i;
            --j;
        }
    }
};
