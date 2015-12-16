#include <vector>

using std::vector;

class MaximumSubarray {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int result = nums[0];
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (last > 0)
                last += nums[i];
            else
                last = nums[i];
            if (result < last)
                result = last;
        }
        return result;
    }
};
