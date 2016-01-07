#include <vector>
#include <stdexcept>

using std::vector;
using std::invalid_argument;

class FindPeakElement {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.empty())
            return -1;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int m = i + (j - i) / 2;
            if (nums[m] < nums[m + 1]) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        return i;
    }
};
