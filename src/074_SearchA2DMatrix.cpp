#include <vector>

using std::vector;

class SearchA2DMatrix {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int b = 0, e = m * n - 1;
        while (b <= e) {
            int mid = b + (e - b) / 2;
            int num = matrix[mid / n][mid % n];
            if (num < target)
                b = mid + 1;
            else if (target < num)
                e = mid - 1;
            else
                return true;
        }
        return false;
    }
};
