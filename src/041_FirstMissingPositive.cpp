#include <vector>

using std::vector;

class FirstMissingPositive {
public:
    int firstMissingPositive(vector<int> &nums) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] <= 0 || nums[i] == i + 1 || nums[i] > n)
                ++i;
            else {
                int tmp = nums[i];
                if (nums[tmp - 1] == tmp) {
                    nums[i] = 0;
                } else {
                    nums[i] = nums[tmp - 1];
                    nums[tmp - 1] = tmp;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n)
                return i + 1;
        }
        return n + 1;
    }
};
