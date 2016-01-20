#include <vector>
#include <deque>

using std::vector;
using std::deque;

class SlidingWindowMaximum {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.empty() || k <= 0)
            return vector<int>();
        vector<int> result;
        deque<int> maxNums;
        for (int i = 0; i < nums.size(); ++i) {
            while (!maxNums.empty() && nums[i] > maxNums.back())
                maxNums.pop_back();
            maxNums.push_back(nums[i]);
            if (i >= k - 1) {
                result.push_back(maxNums.front());
                if (maxNums.front() == nums[i - k + 1])
                    maxNums.pop_front();
            }
        }
        return result;
    }
};
