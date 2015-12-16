#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::invalid_argument;
using std::sort;
using std::abs;

class ThreeSumClosest {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        if (nums.size() < 3)
            throw invalid_argument("nums size less than thress");
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for (unsigned int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - result))
                    result = sum;
                if (sum < target) {
                    ++j;
                } else if (target < sum) {
                    --k;
                } else {
                    result = target;
                    break;
                }
            }
        }
        return result;
    }
};
