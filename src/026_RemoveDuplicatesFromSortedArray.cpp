#include <vector>

using std::vector;

class RemoveDuplicatesFromSortedArray {
public:
    int removeDuplicates(vector<int> &nums) {
        /*
        if (nums.empty())
            return 0;
        int i = 1;
        while (i < nums.size() && nums[i] != nums[i -1])
            ++i;
        int j = i;
        while (j < nums.size()) {
            while (j < nums.size() && nums[j] == nums[j - 1])
                ++j;
            if (j < nums.size())
                nums[i++] = nums[j++];
        }
        return i;
        */

        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++count;
            } else {
                nums[i - count] = nums[i];
            }
        }
        return nums.size() - count;
    }
};
