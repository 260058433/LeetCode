#include <vector>
#include <algorithm>

using std::vector;
using std::binary_search;

class SearchA2DMatrixII {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        //time O(m + n)
        if (matrix.empty() || matrix[0].empty())
            return false;
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] < target)
                ++j;
            else if (matrix[i][j] > target)
                --i;
            else
                return true;
        }
        return false;

        //It's not O(log m + log n)
        /*
        if (matrix.empty() || matrix[0].empty())
            return false;
        return binarySearch(matrix, 0, 0, matrix.size(), matrix[0].size(), target);
        */

        //time O(m * log n)
        /*
        if (matrix.empty() || matrix[0].empty())
            return false;
        return binarySearchRow(matrix, 0, matrix.size(), target);
        */
    }

private:
    bool binarySearch(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2, int target) {
        if (x1 >= x2 || y1 >= y2)
            return false;
        int i = x1 + (x2 - x1) / 2, j = y1 + (y2 - y1) / 2;
        if (matrix[i][j] < target)
            return binarySearch(matrix, i + 1, j + 1, x2, y2, target) || binarySearch(matrix, x1, j + 1, i + 1, y2, target) || binarySearch(matrix, i + 1, y1, x2, j + 1, target);
        else if (matrix[i][j] > target)
            return binarySearch(matrix, x1, y1, i, j, target) || binarySearch(matrix, x1, j, i, y2, target) || binarySearch(matrix, i, y1, x2, j, target);
        else
            return true;
    }

    bool binarySearchRow(vector<vector<int>> &matrix, int top, int bottom, int target) {
        if (top == bottom)
            return false;
        int mid = top + (bottom - top) / 2;
        if (matrix[mid].front() <= target && matrix[mid].back() >= target && binary_search(matrix[mid].begin(), matrix[mid].end(), target))
            return true;
        if (binarySearchRow(matrix, top, mid, target))
            return true;
        if (binarySearchRow(matrix, mid + 1, bottom, target))
            return true;
        return false;
    }
};
