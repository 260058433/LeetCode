#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class FourSum {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            while (j < nums.size()) {
                int k = j + 1, l = nums.size() - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        do {
                            ++k;
                        } while (k < l && nums[k] == nums[k - 1]);
                    } else if (target < sum) {
                        do {
                            --l;
                        } while (k < l && nums[l] == nums[l + 1]);
                    } else {
                        vector<int> line;
                        line.push_back(nums[i]);
                        line.push_back(nums[j]);
                        line.push_back(nums[k]);
                        line.push_back(nums[l]);
                        result.push_back(line);
                        do {
                            ++k;
                        } while (k < l && nums[k] == nums[k - 1]);
                        do {
                            --l;
                        } while (k < l && nums[l] == nums[l + 1]);
                    }
                }
                do {
                    ++j;
                } while (j < nums.size() && nums[j] == nums[j - 1]);
            }
            do {
                ++i;
            } while (i < nums.size() && nums[i] == nums[i - 1]);
        }
        return result;
    }
};
