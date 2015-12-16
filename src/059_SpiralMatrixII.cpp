#include <vector>

using std::vector;

class SpiralMatrixII {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int i = 0, j = n - 1, k = 0, l = n - 1;
        int num = 1;
        while (i <= j && k <= l) {
            for (int a = k; a <= l; ++a)
                result[i][a] = num++;
            ++i;
            for (int a = i; a <= j; ++a)
                result[a][l] = num++;
            --l;
            if (i <= j) {
                for (int a = l; a >= k; --a)
                    result[j][a] = num++;
                --j;
            }
            if (k <= l) {
                for (int a = j; a >= i; --a)
                    result[a][k] = num++;
                ++k;
            }
        }
        return result;
    }
};
