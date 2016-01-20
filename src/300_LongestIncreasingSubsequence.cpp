#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;
using std::make_pair;
using std::move;
using std::lower_bound;


class LongestIncreasingSubsequence {
public:
    int lengthOfLIS(vector<int> &nums) {
        //time O(n ^ 2)
        /*
        int result = 0;
        vector<int> lengths(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i] && lengths[j] >= lengths[i])
                    lengths[i] = lengths[j] + 1;
            if (result < lengths[i])
                result = lengths[i];
        }
        return result;
        */

        //time O(n)
        vector<int> dp;
        for (auto p = nums.begin(); p != nums.end(); ++p) {
            auto q = lower_bound(dp.begin(), dp.end(), *p);
            if (q == dp.end())
                dp.push_back(*p);
            else
                *q = *p;
        }
        return dp.size();
    }
};
