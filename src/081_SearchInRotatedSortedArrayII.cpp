#include <vector>

using std::vector;

class SearchInRotatedSortedArrayII {
public:
    bool search(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j && nums[j] == nums[0])
            --j;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (nums[0] <= nums[m])
                i = m + 1;
            else
                j = m - 1;
        }
        int start = i;
        i = 0;
        j = nums.size() - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            int p = (start + m) % nums.size();
            if (nums[p] < target)
                i = m + 1;
            else if (target < nums[p])
                j = m - 1;
            else
                return true;
        }
        return false;
    }
};
