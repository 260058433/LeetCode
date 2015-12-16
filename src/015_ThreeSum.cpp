#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;

class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            if (nums[i] > 0)
                break;
            int j = i + 1, k = nums.size() - 1; 
            int target = - nums[i];
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    result.push_back(tmp);
                    while (j < k && nums[j] == nums[j + 1])
                        ++j;
                    while (j < k && nums[k] == nums[k - 1])
                        --k;
                    ++j;
                    --k;
                } else if (nums[j] + nums[k] < target) {
                    ++j;
                } else {
                    --k;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
       }
        return result;
    }
};
