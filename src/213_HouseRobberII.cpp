#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class HouseRobberII {
public:
    int rob(vector<int> &nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        int ppre = 0, pre = 0, cur = 0;
        for (int i = 0; i < n - 1; ++i) {
            int tmp = max(pre, ppre + nums[i]);
            ppre = pre;
            pre = tmp;
        }
        int result = pre;
        ppre = 0;
        pre = 0;
        for (int i = 1; i < n; ++i) {
            int tmp = max(pre, ppre + nums[i]);
            ppre = pre;
            pre = tmp;
        }
        result = max(result, pre);
        return result;
    }
};
