#include <vector>
#include <algorithm>

using std::vector;
using std::min;

class MinimumSizeSubarraySum {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int i = 0, j = 0, sum = 0;
        int result = nums.size() + 1;
        while (j < nums.size()) {
            sum += nums[j++];
            while (sum >= s) {
                result = min(result, j - i);
                sum -= nums[i++];
            }
        }
        return result == nums.size() + 1 ? 0 : result;
    }
};
