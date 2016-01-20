#include <vector>
#include <algorithm>

using std::vector;
using std::reverse;
using std::min;
using std::swap;

class RotateArray {
public:
    void rotate(vector<int> &nums, int k) {
        /*
        k = k % nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
        */

        int n = nums.size();
        int i = 0;
        while (k %= n) {
            for (int j = 0; j < k; ++j)
                swap(nums[i + j], nums[nums.size() - k + j]);
            i += k;
            n -= k;
        }
    }
};
