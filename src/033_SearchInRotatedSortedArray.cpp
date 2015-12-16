#include <vector>

using std::vector;

class SearchInRotatedSortedArray {
public:
    int search(vector<int> &nums, int target) {
        int b = 0, e = nums.size() - 1;
        while (b <= e) {
            int m = b + (e - b) / 2;
            if (nums[m] < target) {
                if (nums[m] <= nums[e] && nums[e] < target) {
                    e = m - 1;
                } else {
                    b = m + 1;
                }
            } else if (target < nums[m]) {
                if (nums[e] < nums[m] && target < nums[b]) {
                    b = m + 1;
                } else {
                    e = m - 1;
                }
            } else {
                return m;
            }
        }
        return -1;
    }
};
