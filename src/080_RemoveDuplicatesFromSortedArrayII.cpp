#include <vector>

using std::vector;

class RemoveDuplicatesFromSortedArrayII {
public:
    int removeDuplicates(vector<int> &nums) {
        /*
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i - count] = nums[i];
            if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
                nums[i - count] = nums[i];
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
                ++count;
            }
        }
        return nums.size() - count;
        */

        if (nums.size() <= 2)
            return nums.size();
        int i = 2;
        for (int j = 2; j < nums.size(); ++j) {
            if (nums[i - 2] != nums[j])
                nums[i++] = nums[j];
        }
        return i;
    }
};
