#include <vector>

using std::vector;

class FindMinimumInRotatedSortedArrayII {
public:
    int findMin(vector<int> &nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] == nums[j])
                --j;
            if (nums[i] <= nums[j])
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
