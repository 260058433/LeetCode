#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;
using std::swap;

class MaximumProductSubarray {
public:
    int maxProduct(vector<int> &nums) {
        /*
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int result = 0;
        int negative = 0, positive = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                int tmp = positive;
                positive = negative * nums[i];
                negative = min(tmp * nums[i], nums[i]);
            } else if (nums[i] > 0) {
                positive = max(nums[i], positive * nums[i]);
                negative = negative * nums[i];
            } else {
                positive = 0;
                negative = 0;
            }
            if (result < positive)
                result = positive;
        }
        return result;
        */

        if (nums.empty())
            return 0;
        int result = nums[0];
        int curMax = 1, curMin = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0)
                swap(curMax, curMin);
            curMax = max(curMax * nums[i], nums[i]);
            curMin = min(curMin * nums[i], nums[i]);
            if (result < curMax)
                result = curMax;
        }
        return result;
    }
};
