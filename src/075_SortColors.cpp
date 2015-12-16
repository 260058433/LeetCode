#include <vector>
#include <algorithm>

using std::vector;
using std::swap;

class SortColors {
public:
    void sortColors(vector<int> &nums) {
        int zero = 0, two = nums.size() - 1;
        for (int i = 0; i <= two; ) {
            if (nums[i] == 0 && zero < i)
                swap(nums[zero++], nums[i]);
            else if (nums[i] == 2 && i < two)
                swap(nums[two--], nums[i]);
            else
                ++i;
        }
    }
};
