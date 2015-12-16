#include <vector>

using std::vector;

class SearchInsertPosition {
    int searchInsert(vector<int> &nums, int target) {
        int b = 0, e = nums.size() - 1;
        while (b <= e) {
            int m = b + (e - b) / 2;
            if (nums[m] < target) {
                b = m + 1;
            } else if (target < nums[m]) {
                e = m - 1;
            } else {
                b = m;
                break;
            }
        }
        return b;
    }
};
