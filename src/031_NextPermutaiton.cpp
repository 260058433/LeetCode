#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;

class NextPermutation {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.empty())
            return;
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1])
            --i;
        if (i > 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i - 1])
                --j;
            nums[i - 1] += nums[j];
            nums[j] = nums[i - 1] - nums[j];
            nums[i - 1] -= nums[j]; 
        }
        reverse(nums.begin() + i, nums.end());
    }
};
