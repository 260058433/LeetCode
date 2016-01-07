#include <vector>

using std::vector;

class FindMinimumInRotatedSortedArray {
public:
    int findMin(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] < nums[j])
                break;
            int m = i + (j - i) / 2;
            if (nums[i] <= nums[m]) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        return nums[i];
    }
};
