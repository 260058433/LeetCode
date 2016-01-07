#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class MaximumGap {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;
        int n = nums.size();
        int minNum = nums[0], maxNum = nums[0];
        for (int i = 1; i < n; ++i) {
            if (minNum > nums[i])
                minNum = nums[i];
            if (maxNum < nums[i])
                maxNum = nums[i];
        }
        int interval = (maxNum - minNum + 1) / (n - 1);
        if ((maxNum - minNum + 1) % (n - 1))
            ++interval;
        vector<int> maxRegion(n - 1, -1), minRegion(n - 1, -1);
        for (int i = 0; i < n; ++i) {
            int j = (nums[i] - minNum) / interval;
            if (maxRegion[j] == -1 || nums[maxRegion[j]] < nums[i])
                maxRegion[j] = i;
            if (minRegion[j] == -1 || nums[minRegion[j]] > nums[i])
                minRegion[j] = i;
        }
        int result = interval - 1;
        int pre = nums[maxRegion[0]];
        for (int i = 1; i < n - 1; ++i) {
            if (minRegion[i] == -1)
                continue;
            if (result < nums[minRegion[i]] - pre)
                result = nums[minRegion[i]] - pre;
            pre = nums[maxRegion[i]];
        }
        return result;
    }
};
