#include <vector>

using std::vector;

class PascalsTriangle {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex, 1);
        for (int i = 0; i < rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                result[j] += result[j - 1];
            }
        }
        return result;
    }
};