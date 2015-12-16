#include <vector>

using std::vector;

class SearchForARange {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int b = 0, e = nums.size() - 1;
        vector<int> result;
        while (b <= e) {
            int m = b + (e - b) / 2;
            if (nums[m] < target) {
                b = m + 1;
            } else {
                e = m - 1;
            }
        }
        if (b == nums.size() || nums[b] != target)
            return vector<int>(2, -1);
        result.push_back(b);
        e = nums.size() - 1;
        while (b <= e) {
            int m = b + (e - b) / 2;
            if (nums[m] <= target) {
                b = m + 1;
            } else {
                e = m - 1;
            }
        }
        result.push_back(e);
        return result;
    }
};
